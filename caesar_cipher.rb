def caesar_cipher(string, shift)
  string.split(//).map do |l|
    if l =~ /[A-Z]/
      (65 + (l.ord - 65 + (shift % 26)) % 26).chr
    elsif l =~ /[a-z]/
      (97 + (l.ord - 97 + (shift % 26)) % 26).chr
    else
      l
    end
  end.join
end
