class CreateReports < ActiveRecord::Migration
  def change
    create_table :reports do |t|
      t.float :price
      t.integer :quantity

      t.timestamps null: false
    end
  end
end
