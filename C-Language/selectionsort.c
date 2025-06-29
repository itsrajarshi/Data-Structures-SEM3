#include<stdio.h>
int selectionsort(int a[],int n)
{
  int i,j,min,temp;
  for(i = 0;i<n-1;i++)
  {
    min = i;
    for(j = i+1;j<n;j++)
    {
      if(a[j]<a[min])
      {
        min = j;
      }
    }
    temp = a[min];
    a[min] = a[i];
    a[i] = temp;
  }
}

int main()
{
  int a[5] = {6,9,4,2,3};
  int n = sizeof(a)/sizeof(a[0]);  
  selectionsort(a,n);  
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  printf( "\n");
  return 0;
}