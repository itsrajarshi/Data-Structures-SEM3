def selectionsort(a, n):
  for i in range(n-1):
    min = i
    for j in range(i+1, n):
      if a[j] < a[min]:
        min = j
    temp = a[min]
    a[min] = a[i]
    a[i] = temp

def main():
  a = [6,9,4,2,3]
  n = len(a)  
  selectionsort(a,n)  
  for i in range(n):
    print(a[i], end=" ")
  print()

if __name__ == "__main__":
  main()