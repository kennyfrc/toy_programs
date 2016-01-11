json.array!(@products) do |product|
  json.extract! product, :id, :name, :stock_level, :date, :units_sold, :retail_price
  json.url product_url(product, format: :json)
end
