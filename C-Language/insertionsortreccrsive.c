// #include <stdio.h>

// int insertionsort(int a[], int n)
// {
//   int i,j,temp;
//   for(i=1;i<n;i++)
//     {
//       temp = a[i];
//       for(j=i-1;j>=0;j--)
//         {
//           if(a[j]>temp)
//           {
//             a[j+1] = a[j];
//             a[j] = temp;
//           }
//         }
//     }
// }

#include <stdio.h>

// int binarysearch(int a[], int low, int high, int key) {
//   int mid;
//   if (high >= low) {
//     mid = (low + high) / 2;
//     if (a[mid] == key)
//       return mid;
//     if (a[mid] < key)
//       return binarysearch(a, mid + 1, high, key);
//     else
//       return binarysearch(a, low, mid - 1, key);
//   }
//   return -1;
// }

int insertionsort(int a[], int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
    {
      temp = a[i];
      for(j=i-1;j>=0;j--)
        {
          if(a[j]>temp)
            return(a[j+1] = a[j]);
          a[j+1] = temp;
        }
    }
}
int main()
{
  int n,i,a[20];
  printf("enter the no of elements");
  scanf("%d", &n);
  printf("enter element");
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);
  insertionsort(a,n);
  printf("sorted array");
  printf("%d",a[i]);
}