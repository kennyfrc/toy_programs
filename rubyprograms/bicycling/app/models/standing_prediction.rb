# == Schema Information
#
# Table name: standing_predictions
#
#  id         :integer          not null, primary key
#  manager_id :integer
#  tour_id    :integer
#  cyclist_id :integer
#  rank       :integer
#  created_at :datetime         not null
#  updated_at :datetime         not null
#

class StandingPrediction < ActiveRecord::Base
  belongs_to :cyclist
  belongs_to :manager
  belongs_to :tour

  validates_presence_of :tour_id, :cyclist_id, :manager_id, :rank # you can have two diff managers betting on the same cyclists on teh same tour with different ranks (??)
  validates_uniqueness_of :rank, :scope => [:tour_id, :cyclist_id, :manager_id] 
end
