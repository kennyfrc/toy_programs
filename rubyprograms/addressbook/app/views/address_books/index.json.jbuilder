json.array!(@address_books) do |address_book|
  json.extract! address_book, :id, :name
  json.url address_book_url(address_book, format: :json)
end
