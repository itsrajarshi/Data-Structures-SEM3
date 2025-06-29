def insertionsort(a,n,low,high):
  for i in range(low,high):
    key = a[i]
    j = i - 1
    while j >= 0 and key < a[j]:
      a[j + 1] = a[j]
      j -= 1
    a[j + 1] = key

def main():
  n = int(input("enter the no of elements: "))
  a = [int(input("enter element: ")) for i in range(n)]
  insertionsort(a,n,0,n-1)
  print(a)
if __name__ == "__main__":
  main()