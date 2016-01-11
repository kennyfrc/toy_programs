class CreateProducts < ActiveRecord::Migration
  def change
    create_table :products do |t|
      t.string :name
      t.integer :stock_level
      t.datetime :date
      t.integer :units_sold
      t.integer :retail_price_in_cents

      t.timestamps null: false
    end
  end
end
