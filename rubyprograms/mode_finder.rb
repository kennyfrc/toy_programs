return puts "Please Enter a Set of Digits as Inputs" if ARGV.empty?

arr = ARGV.map(&:to_i)
arr2 = []

arr.uniq.each do |e|
  arr2 << e << arr.count(e)
end

h = Hash[*arr2]
mode = h.select { |k,v| v == h.values.max }.keys

puts "Mode(s): #{mode}"
