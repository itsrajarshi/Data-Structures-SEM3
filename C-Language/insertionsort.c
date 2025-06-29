#include <stdio.h>

int insertionsort(int a[], int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
    {
      temp = a[i];
      for(j=i-1;j>=0;j--)
        {
          if(a[j]>temp)
          {
            a[j+1] = a[j];
            a[j] = temp;
          }
        }
    }
}

int main()
{
  int n,i,a[20];
  printf("enter the no of elements");  
  scanf("%d",&n); 
  printf("enter elements");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  insertionsort(a,n);
  printf("sorted array");
  for(i=0;i<n;i++)
    printf("%d",a[i]);
}