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

require 'test_helper'

class StandingPredictionTest < ActiveSupport::TestCase
  # test "the truth" do
  #   assert true
  # end
end
