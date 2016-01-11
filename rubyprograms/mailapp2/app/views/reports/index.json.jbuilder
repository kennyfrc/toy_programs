json.array!(@reports) do |report|
  json.extract! report, :id, :price, :quantity
  json.url report_url(report, format: :json)
end
