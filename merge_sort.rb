# merge sort
# O(log n) 

# TODO comment

def merge_sort(array)
  if array.length <= 1
    return array
  end
  middle = array.length / 2
  left = array[0, middle]
  right = array[middle, array.length]
  merge(merge_sort(left), merge_sort(right))
end

def merge(left, right)
  result = []
  while !left.empty? && !right.empty?
    if left.first <= right.first
      result.push(left.shift)
    else
      result.push(right.shift)
    end
  end
  result.push(left.shift) if left.length > 0
  result.push(right.shift) if right.length > 0
  return result
end
