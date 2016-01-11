# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)
Product.create!(name: "Settlers of Catan", price: 34.95, released_on: rand(1..90).days.ago)
Product.create!(name: "Red Shirt", price: 12.49, released_on: rand(1..90).days.ago)
Product.create!(name: "Technodrome", price: 27.99, released_on: rand(1..90).days.ago)
Product.create!(name: "Acoustic Guitar", price: 1025.00, released_on: rand(1..90).days.ago)
Product.create!(name: "Agricola", price: 45.99, released_on: rand(1..90).days.ago)