// sequential search
#include <stdio.h>

int main(void)
{
  int a[20], n, k, found = 0, i;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  printf("Enter the elements of the array: ");
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("enter the value to be searched: ");
  scanf("%d", &k);
  for(i = 0; i < n; i++)
    {
      if(a[i] == k)
      {
        found = 1;
        printf("element found at %d\n",i);
        break;
      }
    }
  if(found == 0)
    printf("element not found");
}