#include <stdio.h>
int merge(int list[], int sorted[], int left, int mid, int right) {
  int i = left, j = mid + 1, k = left;
  int inv_count = 0;

  while (i <= mid && j <= right) {
    if (list[i] <= list[j])
      sorted[k++] = list[i++];
    else {
      sorted[k++] = list[j++];
      inv_count += (mid - i + 1);
    }
  }
  while (i <= mid)
    sorted[k++] = list[i++];
  while (j <= right)
    sorted[k++] = list[j++];
  for (i = left; i <= right; i++)
    list[i] = sorted[i];
  return inv_count;
}

int mergesort(int list[], int sorted[], int left, int right) {
  int inv_count = 0;
  if (left < right) {
    int mid = (left + right) / 2;
    inv_count += mergesort(list, sorted, left, mid);
    inv_count += mergesort(list, sorted, mid + 1, right);
    inv_count += merge(list, sorted, left, mid, right);
  }
  return inv_count;
}
int main()
{
  int list[] = {6,9,4,2,0,1};
  int sorted[6];
  int size = sizeof(list)/sizeof(list[0]);
  int inv_count = mergesort(list,sorted,0,size-1);
  printf("sorted array: ");
  for(int i = 0; i<size;i++)
    printf("%d",list[i]);
  printf("\n");
  printf("number of inversions are %d\n",inv_count);
  return 0;
}