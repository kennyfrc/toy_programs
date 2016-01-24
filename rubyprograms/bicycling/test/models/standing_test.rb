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

require 'test_helper'

class StandingTest < ActiveSupport::TestCase
  # test "the truth" do
  #   assert true
  # end
end
