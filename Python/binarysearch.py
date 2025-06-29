def binarysearch(a, low, high, key):
  mid = 0
  while low <= high:
    mid = low + (high - low) // 2
    if a[mid] == key:
      return mid
    if a[mid] > key:
      high = mid - 1
    else:
      low = mid + 1
  return -1

def main():
  n = int(input("enter the no of elements: "))
  a = [int(input("enter element: ")) for i in range(n)]
  key = int(input("enter key: "))
  result = binarysearch(a, 0, n - 1, key)
  if result == -1:
    print("not found")
  else:
    print(result)

if __name__ == "__main__":
  main()
