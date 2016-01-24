class PagesController < ApplicationController
  def home
    # this is a rule where if a user is logged in, then the application will redirect him/her to the root-Path
    if current_user
      redirect_to movies_path
    end
  end
end
