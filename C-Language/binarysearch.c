#include <stdio.h>
int binarysearch(int a[], int low, int high, int key)
{
  int mid;
  while(low<=high)
    {
      mid = low + (high-low)/2;
      if (a[mid]==key)
        return mid;
      if (a[mid]>key)
        high = mid -1;
      else
        low = mid +1;
    }
  return -1;
}

int main()
{
  int n, i,result,key;
  int a[20];
  printf("enter the no of elements");
  scanf("%d", &n);
  printf("enter element");
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);
  printf("enter key");
  scanf("%d",&key);
  result = binarysearch(a,0,n-1,key);
  if(result == -1)
    printf("not found");
  else
    printf("%d",result);
}
