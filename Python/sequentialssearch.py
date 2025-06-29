def sequentialsearch(a,n,key):
  for i in range(n):
    if a[i] == key:
      return i
  return -1

def main():
  n = int(input("enter the no of elements: "))
  a = [int(input("enter element: ")) for i in range(n)]
  key = int(input("enter key: "))
  result = sequentialsearch(a,n,key)
  if result == -1:
    print("not found")
  else:
    print(result)
if __name__ == "__main__":
  main()
