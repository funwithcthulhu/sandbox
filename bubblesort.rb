# implementation of bubble sort algorithm with for loop
# O(n^2) Omega(n)

def bubble_sort(arr)
  swap = -1

  # if no swaps, stop program
  while swap != 0

    # set swap to 0 so we can check for swaps
    swap = 0
    n = arr.size - 2

    # don't compare last element in array to nil
    (0..n).each do |i|

      # look at adjacent elements, if in wrong order, swap them
      next unless arr[i] > arr[i + 1]
      arr[i], arr[i + 1] = arr[i + 1], arr[i]

      # add a swap counter if we swapped something
      swap += 1
    end
  end
  arr
end

# with .times instead of .each
def bubble_sort(arr)
  swap = -1
  while swap != 0
    swap = 0
    n = arr.size - 1
    n.times do |i|
      next unless arr[i] > arr[i + 1]
      swap += 1
      arr[i], arr[i + 1] = arr[i + 1], arr[i]
    end
  end
  arr
end
