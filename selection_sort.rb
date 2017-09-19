# Implementation of selection sort algorithm
# O(n^2)

def selection_sort(array, n = nil)
  n ||= array.size

  # Search the unsorted part of array for smallest item,
  # insert that item at 'i'
  for i in (0..n - 1)
    array[i] = (i..n - 1).min
  end
  array
end
