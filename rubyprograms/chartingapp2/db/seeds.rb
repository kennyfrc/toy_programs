# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)

Product.delete_all
Product.create sku:"0001"
Product.create sku:"0002"
products = Product.all

ProductDescription.create name: "Banana", product: products.find_by(sku: "0001")
ProductDescription.create name: "Apple", product: products.find_by(sku: "0002")

#Banana Purchases
Purchase.create price_in_cents: 2999, units_purchased: 40, created_at: DateTime.now - 5.days, product: products.find_by(sku: "0001")
Purchase.create price_in_cents: 2999, units_purchased: 30, created_at: DateTime.now - 4.days, product: products.find_by(sku: "0001")
Purchase.create price_in_cents: 2999, units_purchased: 40, created_at: DateTime.now - 3.days, product: products.find_by(sku: "0001")
Purchase.create price_in_cents: 2999, units_purchased: 40, created_at: DateTime.now - 2.days, product: products.find_by(sku: "0001")
Purchase.create price_in_cents: 2999, units_purchased: 30, created_at: DateTime.now - 1.days, product: products.find_by(sku: "0001")
Purchase.create price_in_cents: 2999, units_purchased: 40, created_at: DateTime.now, product: products.find_by(sku: "0001")

#Apple Purchase
Purchase.create price_in_cents: 1999, units_purchased: 30, created_at: DateTime.now - 5.days, product: products.find_by(sku: "0002")
Purchase.create price_in_cents: 1999, units_purchased: 99, created_at: DateTime.now - 4.days, product: products.find_by(sku: "0002")
Purchase.create price_in_cents: 2999, units_purchased: 40, created_at: DateTime.now - 3.days, product: products.find_by(sku: "0002")
Purchase.create price_in_cents: 1999, units_purchased: 40, created_at: DateTime.now - 2.days, product: products.find_by(sku: "0002")
Purchase.create price_in_cents: 1999, units_purchased: 60, created_at: DateTime.now - 1.days, product: products.find_by(sku: "0002")
Purchase.create price_in_cents: 1999, units_purchased: 45, created_at: DateTime.now, product: products.find_by(sku: "0002")


#Banana Sales
Sale.create price_in_cents: 4999, units_sold: 20, created_at: DateTime.now - 5.days, product: products.find_by(sku: "0001")
Sale.create price_in_cents: 4999, units_sold: 15, created_at: DateTime.now - 4.days, product: products.find_by(sku: "0001")
Sale.create price_in_cents: 4999, units_sold: 15, created_at: DateTime.now - 3.days, product: products.find_by(sku: "0001")
Sale.create price_in_cents: 4999, units_sold: 25, created_at: DateTime.now - 2.days, product: products.find_by(sku: "0001")
Sale.create price_in_cents: 4999, units_sold: 30, created_at: DateTime.now - 1.days, product: products.find_by(sku: "0001")
Sale.create price_in_cents: 4999, units_sold: 35, created_at: DateTime.now, product: products.find_by(sku: "0001")

#Apple Sales
Sale.create price_in_cents: 3999, units_sold: 10, created_at: DateTime.now - 5.days, product: products.find_by(sku: "0002")
Sale.create price_in_cents: 3999, units_sold: 35, created_at: DateTime.now - 4.days, product: products.find_by(sku: "0002")
Sale.create price_in_cents: 3999, units_sold: 15, created_at: DateTime.now - 3.days, product: products.find_by(sku: "0002")
Sale.create price_in_cents: 3999, units_sold: 45, created_at: DateTime.now - 2.days, product: products.find_by(sku: "0002")
Sale.create price_in_cents: 3999, units_sold: 50, created_at: DateTime.now - 1.days, product: products.find_by(sku: "0002")
Sale.create price_in_cents: 999, units_sold: 90, created_at: DateTime.now, product: products.find_by(sku: "0002")

