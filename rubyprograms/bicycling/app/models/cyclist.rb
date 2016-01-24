# == Schema Information
#
# Table name: cyclists
#
#  id         :integer          not null, primary key
#  name       :string
#  created_at :datetime         not null
#  updated_at :datetime         not null
#

class Cyclist < ActiveRecord::Base
  has_many :standings
  has_many :standing_predictions

  validates_presence_of :name
end
