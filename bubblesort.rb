# implementation of bubble sort algorithm with for loop
def bubble_sort(arr)
  swap = -1

  # if no swaps, stop program
  while swap != 0

    # set swap to 0 so we can check for swaps
    swap = 0
    n = arr.size

    # don't compare last element in array to nil
    for i in (0..n - 2)

      # look at adjacent elements, if in wrong order, swap them
      if arr[i] > arr[i + 1]
        arr[i], arr[i + 1] = arr[i + 1], arr[i]

        # add a swap counter if we swapped something
        swap += 1
      end
    end
  end
  arr
end

# more "ruby-like" implementation with .times instead of for-loop
def bubble_sort(arr)
  swap = -1
  while swap != 0
    swap = 0
    n = arr.size
    (n - 1).times do |i|
      if arr[i] > arr[i + 1]
        arr[i], arr[i + 1] = arr[i + 1], arr[i]
        swap += 1
      end
    end
  end
  arr
end