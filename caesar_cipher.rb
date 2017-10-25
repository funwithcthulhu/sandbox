def caesar_cipher(string, shift)
  parse = ->(l, mod) { (mod + (l.ord - mod + (shift % 26)) % 26).chr }
  string.split(//).map do |l|
    if l =~ /[A-Z]/
      parse[l, 64]
    elsif l =~ /[a-z]/
      parse[l, 97]
    else
      l
    end
  end.join
end
