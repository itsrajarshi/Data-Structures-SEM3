def bubblesort(a,n,low,high):
  mid = 0
  for i in range(low,high):
    for j in range(low,high-i):
      if a[j]>a[j+1]:
        a[j],a[j+1]=a[j+1],a[j]

def binary_search(a, key, low, high):
  while low <= high:
    mid = low + (high - low) // 2
    if a[mid] == key:
      return mid
    elif a[mid] > key:
      high = mid - 1
    else:
      low = mid + 1
  return -1

def main():
  n = int(input("enter the no of elements: "))
  a = [int(input("enter element: ")) for i in range(n)]
  key = int(input("enter key: "))
  bubblesort(a,n,0,n-1)
  result = binary_search(a, key, 0, n - 1)
  if result == -1:
    print("not found")
  else:
    print(result)
if __name__ == "__main__":
  main()