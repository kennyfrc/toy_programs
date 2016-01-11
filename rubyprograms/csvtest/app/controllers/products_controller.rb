class ProductsController < ApplicationController
  def index
    @products = Product.order(:name)
    respond_to do |format|
      format.html
      format.csv { send_data @products.to_csv }
      format.xls # { send_data @products.to_csv(col_sep: "\t") }
    end
  end

  def import
    # takes the file being uplaoded and puts it into our products database => params[:file]
    Product.import(params[:id])
    redirect_to root_url, notice: "Products Imported"
  end
end
