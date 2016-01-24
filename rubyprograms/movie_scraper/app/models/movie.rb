class Movie < ActiveRecord::Base
  belongs_to :user

  validates_presence_of :title
  validates :hotness, :numericality => {:allow_blank => true}
  validates :image_url, :url => {:allow_blank => true}
end
