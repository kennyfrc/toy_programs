json.array!(@product_descriptions) do |product_description|
  json.extract! product_description, :id, :name, :product_id
  json.url product_description_url(product_description, format: :json)
end
