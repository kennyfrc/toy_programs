class CreateEntries < ActiveRecord::Migration
  def change
    create_table :entries do |t|
      t.string :name
      t.string :phone_number
      t.string :email
      t.references :address_book, index: true, foreign_key: true

      t.timestamps null: false
    end
  end
end
