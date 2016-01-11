json.array!(@sales) do |sale|
  json.extract! sale, :id, :price_in_cents, :units_sold, :product_id, :customer_id
  json.url sale_url(sale, format: :json)
end
