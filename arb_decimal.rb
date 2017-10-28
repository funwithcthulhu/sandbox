# Program for finding a decimal to an arbitrary precision

def divide(n, p = 20, counter = 1, divisor = 1, decimal = [])
  return decimal.join if counter > p
  if (1.0/n.to_f).round(20).to_s.size <= 12
    return (1.0/n.to_f).to_s.split('.')[1]
  end
  divisor *= 10
  until !(divisor / n).zero?
    divisor *= 10
    decimal << 0
  end
  temp_d = divisor / n
  remainder = divisor - (temp_d * n)
  decimal << temp_d
  divisor = remainder
  counter += 1
  divide(n, p, counter, divisor, decimal)
end