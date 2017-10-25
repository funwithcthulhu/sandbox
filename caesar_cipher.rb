def caesar_cipher(string, shift)
  string.split(//).map do |l|
    if l =~ /[A-Z]/
      shift(l, shift, 90)
    elsif l =~ /[a-z]/
      shift(l, shift, 122)
    else
      l
    end
  end.join
end

def shift(l, s, mod)
  return (l.ord + (s % 26)).chr unless l.ord + (s % 26) > mod
  (l.ord + (s % 26) - 26).chr
end
