class Product < ActiveRecord::Base

  scope :top_sellers, ->{all.sort{|a,b| b.revenue <=> a.revenue}.take(2)}

  def retail_price
    retail_price_in_cents.to_f / 100 || read_attribute(:retail_price)
  end

  def retail_price=(p)
    write_attribute(:retail_price_in_cents, p.to_f.round(2) * 100)
  end

  def revenue
    retail_price * units_sold
  end

end


# f.text_field :retail_price
