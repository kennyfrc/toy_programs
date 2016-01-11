json.array!(@purchases) do |purchase|
  json.extract! purchase, :id, :price_in_cents, :units_purchased, :product_id, :supplier_id
  json.url purchase_url(purchase, format: :json)
end
