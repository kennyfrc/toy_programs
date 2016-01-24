# == Schema Information
#
# Table name: managers
#
#  id         :integer          not null, primary key
#  created_at :datetime         not null
#  updated_at :datetime         not null
#

class Manager < ActiveRecord::Base
  has_many :standing_predictions
end
