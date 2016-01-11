class CreateSales < ActiveRecord::Migration
  def change
    create_table :sales do |t|
      t.integer :price_in_cents
      t.integer :units_sold
      t.references :product, index: true, foreign_key: true
      t.references :customer, index: true, foreign_key: true

      t.timestamps null: false
    end
  end
end
