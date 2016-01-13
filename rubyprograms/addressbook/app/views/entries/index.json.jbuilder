json.array!(@entries) do |entry|
  json.extract! entry, :id, :name, :phone_number, :email, :address_book_id
  json.url entry_url(entry, format: :json)
end
