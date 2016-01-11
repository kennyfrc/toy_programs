class Product < ActiveRecord::Base
  attr_accessible :name, :price, :released_on
  
  def self.to_csv(options = {})
    CSV.generate(options) do |csv|
      csv << column_names
      all.each do |product|
        csv << product.attributes.values_at(*column_names)
      end
    end
  end

  def self.import(file)
    csv_text = File.read(file)
    csv = CSV.parse(csv_text, headers: true, skip_blanks: true)
    csv.each do |row|
       row_hash = row.to_hash
       add_entry(row_hash["name"], row_hash["price"], row_hash["released_on"])
     end
  end
end
