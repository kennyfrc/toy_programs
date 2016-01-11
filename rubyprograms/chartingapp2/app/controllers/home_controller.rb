class HomeController < ApplicationController
  def show
    @products = Product.all
    @purchases = Purchase.all
    @sales = Sale.all
    @productdescriptions = ProductDescription.all
  end
end
