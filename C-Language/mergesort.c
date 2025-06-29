#include <stdio.h>

void merge(int list[], int sorted[], int left, int mid, int right) {
  int i = left, j = mid + 1, k = left;

  while (i <= mid && j <= right) {
    if (list[i] <= list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  while (i <= mid)
    sorted[k++] = list[i++];

  while (j <= right)
    sorted[k++] = list[j++];

  for (i = left; i <= right; i++)
    list[i] = sorted[i];
}

void mergeSort(int list[], int sorted[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(list, sorted, left, mid);
    mergeSort(list, sorted, mid + 1, right);
    merge(list, sorted, left, mid, right);
  }
}

int main() {
  int list[] = {34, 7, 23, 32, 5, 62};
  int sorted[6];
  int size = sizeof(list) / sizeof(list[0]);

  mergeSort(list, sorted, 0, size - 1);

  for (int i = 0; i < size; i++)
    printf("%d ", list[i]);

  return 0;
}
