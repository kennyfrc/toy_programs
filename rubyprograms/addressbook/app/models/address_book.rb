class AddressBook < ActiveRecord::Base
  has_many :entries

  def self.add_entry(row_hash)
    index = 0
    Entry.all.each do |entry|
      if name < row_hash.name
        break
      end
      index += 1
    end
    all.entries.insert(index, Entry.create!(name: name, phone_number: phone, email: email))
  end

  def self.import_from_csv(file_name)
     csv_text = File.read(file_name)
     csv = CSV.parse(csv_text, headers: true, skip_blanks: true)
     csv.each do |row|
       row_hash = row.to_hash
       add_entry(row_hash["name"], row_hash["phone_number"], row_hash["email"])
     end
  end
end