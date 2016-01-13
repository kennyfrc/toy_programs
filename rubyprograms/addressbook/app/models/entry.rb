class Entry < ActiveRecord::Base
  belongs_to :address_book

  def self.to_csv
    CSV.generate do |csv|
      csv << column_names
      all.each do |entry|
        csv << entry.attributes.values_at(*column_names)
      end
    end
  end

  def self.text_search(query)
    if query.present?
      where("name ilike :q or phone_number ilike :q or email ilike :q", q: "%#{query}%") # find all the articles that match that query using a like comparision (or in this case it's ilike so that it's case insenstive... now we're comparing the name &&  phone_number && emmail to the query wrapped in the % sign)
    else
      all
    end
  end
end
