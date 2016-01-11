arr = [1,2,3,4,5]

puts arr.map {|e| "#" * e + "\n" }.reduce(:+) + arr.map {|e| "#" * (arr.last - e) + "\n" }.reduce(:+)