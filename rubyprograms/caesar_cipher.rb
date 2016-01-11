def caesar_cipher(str, shift)
  lower_alpha = ("a".."z")
  upper_alpha = ("A".."Z")

  n = shift % 26

  lower_coded = lower_alpha.map.each_with_index { |e, i| e = lower_alpha.to_a[i - n]}
  upper_coded = upper_alpha.map.each_with_index { |e, i| e = upper_alpha.to_a[i - n]}

  lowercase_filter = str.chars.map { |e| !!(e =~ /[a-z]/) ? lower_coded[lower_alpha.to_a.index(e)] : e }.join
  fully_filtered = lowercase_filter.chars.map { |e| !!(e =~ /[A-Z]/) ? upper_coded[upper_alpha.to_a.index(e)] : e }.join
  
  fully_filtered
end