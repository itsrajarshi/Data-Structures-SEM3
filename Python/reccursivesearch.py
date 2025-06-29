def binarysearch(a, low, high, key):
  mid = 0
  if high >= low:
    mid = (low + high) / 2
    if a[mid] == key:
      return mid
    if a[mid] > key:
      return binarysearch(a,mid + 1,high,key)
    else:
      return binarysearch(a,low,mid - 1,key)
  else:
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