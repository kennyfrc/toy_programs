# == Schema Information
#
# Table name: standings
#
#  id         :integer          not null, primary key
#  tour_id    :integer
#  cyclist_id :integer
#  rank       :integer
#  created_at :datetime         not null
#  updated_at :datetime         not null
#

class Standing < ActiveRecord::Base
  belongs_to :cyclist
  belongs_to :tour

  validates_presence_of :tour_id, :cyclist_id, :rank
  validates_uniquness_of :rank, :scope => [:tour_id, :cyclist_id]
end
