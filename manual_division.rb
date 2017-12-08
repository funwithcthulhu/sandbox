# code for manually approximating division to an arbitrary decimal point


def divide(n, divisor = 1, p = 20, counter = 1, decimal = [])
  # baseline
  return decimal.join if counter > p
  # accounts for cases such as 1/8 = 0.125 which otherwise break the program
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
  divide(n, divisor, p, counter, decimal)
end