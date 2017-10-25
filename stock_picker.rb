# Takes an array of stock prices such as [17,3,6,9,15,8,6,1,10],
# each for a hypothetical day, and returns a pair of days
# representing the best day to buy and best day to sell.
# Days start at 0. Must buy before you can sell.

def stock_picker(array)
  cache = {}
  array.each_index do |a|
    array.each_index do |b|
      next unless b > a
      cache[array[b] - array[a]] = [a, b]
    end
  end
  cache[cache.keys.max]
end
