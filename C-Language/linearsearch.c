#include <stdio.h> 

int linearsearch(int a[], int size, int key,int index)
{
  if(a[index]==key)
  {
    return index;
  }
  if(index == size)
  {
    return -1;
  }
}
int main()
{
  int a[20],n,i,key,index,result;
  printf("enter the no of elements");  scanf("%d",&n);  printf("enter element");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("enter key");
  scanf("%d",&key);
  result = linearsearch(a,n,key,index);
  if(result == -1)
    printf("not found");
  else
    printf("%d",result);
}