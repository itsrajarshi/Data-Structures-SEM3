def quicksort(arr):
  if len(arr) <= 1:
    return arr

  pivot = arr[len(arr) // 2]
  left = [x for x in arr if x < pivot]
  middle = [x for x in arr if x == pivot]
  right = [x for x in arr if x > pivot]

  return quicksort(left) + middle + quicksort(right)

if __name__ == "__main__":
  list1 = [34, 7, 23, 32, 5, 62]
  print("input array:",list1)
  sorted_list = quicksort(list1)
  print("output array:",sorted_list)
