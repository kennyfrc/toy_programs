class CreateAddressBooks < ActiveRecord::Migration
  def change
    create_table :address_books do |t|
      t.string :name

      t.timestamps null: false
    end
  end
end
