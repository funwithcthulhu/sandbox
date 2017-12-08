def staircase(n)
  i = n - 1
  k = 1
  n.times do
    print ' '*i + '#' * k + "\n"
    i -= 1
    k += 1
  end
end