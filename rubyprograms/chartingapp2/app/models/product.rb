class Product < ActiveRecord::Base
  has_many :product_descriptions
  has_many :purchases
  has_many :sales


end
