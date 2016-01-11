json.array!(@products) do |product|
  json.extract! product, :id, :sku
  json.url product_url(product, format: :json)
end
