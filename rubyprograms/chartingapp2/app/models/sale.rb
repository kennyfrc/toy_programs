class Sale < ActiveRecord::Base
  belongs_to :product
  belongs_to :customer

  def price
    price_in_cents.to_f / 100 || read_attribute(:price)
  end

  def price=(p)
    write_attribute(:price_in_cents, p.to_f.round(2) * 100)
  end

  def revenue
    price * units_sold
  end
  
end
