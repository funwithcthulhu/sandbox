def divide(n, p = 20, counter = 1, divisor = 1, decimal = [])
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
  divide(n, p, counter, divisor, decimal)
end

def nthroot(a, n = 2, precision = 1e-100)
  x = Float(a)
  begin
    prev = x
    x = ((n - 1) * prev + a / (prev ** (n - 1))) / n
  end while (prev - x).abs > precision
  x 
end

def sroot(n, digits)
  answer = ''
  first = n.to_s.reverse.to_i % 10
  divisor = 
  until answer.size > digits
  end
end

def root(n, p)
  answer = ''

  digs = n.to_s.split(//).reverse.each_slice(2).to_a.each do |x|
    x.map!(&:to_i)
  end.each do |x| x.reverse!
  end.reverse.map { |x| x.join.to_i }

  divisor = 0
  (1..9).each do |x|
    if x**2 <= digs[0] && x**2 > divisor
      divisor = x**2
    end
  end

  until answer.size > digits
    remainder = digs[0] - divisor
    answer += remainder.to_s

    digs.shift
    divisor = "#{remainder} + #{digs[0]}".to_i

    temp = remainder * 2
    (1..9).each do |x|
      if ("#{temp}" + x.to_s).to_i
  end

  