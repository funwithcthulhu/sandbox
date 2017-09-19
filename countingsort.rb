# counting sort in ruby

def counting_sort(arr, n = nil)
  n ||= arr.size
  k = arr.max + 1
  count_arr = Array.new
  result = Array.new

  # set each value of the counting array = 0, with a total size
  # equal to the max val of the input array + 1
  k.times do |x|
    count_arr.push(0)
  end

  # add one to the idx of the count array corresponding to the
  # item in the input array for each item in the input array
  n.times do |i|
    count_arr[arr[i]] += 1
  end

  # sum each idx of the count array with the item behind it
  # this gets us the correct idx for the corresponding item in
  # the original array (equal to the idx of the count array)
  for j in (1...k)
    count_arr[j] += count_arr[j - 1]
  end

  # create output array mapping the item in the input array
  # with the sorted idx of the count array. subtract 1 in case
  # duplicate items are present
  for i in (0...n)
    result[count_arr[arr[i]] - 1] = arr[i]
    count_arr[arr[i]] = count_arr[arr[i]] - 1
  end
  result
end
