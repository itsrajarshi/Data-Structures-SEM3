#include <stdio.h>

int mergeAndCount(int list[], int sorted[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else {
            sorted[k++] = list[j++];
            // All elements from list[i] to list[mid] are greater than list[j]
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
        sorted[k++] = list[i++];

    while (j <= right)
        sorted[k++] = list[j++];

    for (i = left; i <= right; i++)
        list[i] = sorted[i];

    return invCount;
}

int mergeSortAndCount(int list[], int sorted[], int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSortAndCount(list, sorted, left, mid);
        invCount += mergeSortAndCount(list, sorted, mid + 1, right);

        invCount += mergeAndCount(list, sorted, left, mid, right);
    }
    return invCount;
}

int main() {
    int list[] = {34, 7, 23, 32, 5, 62};
    int size = sizeof(list) / sizeof(list[0]);
    int sorted[size];

    int inversionCount = mergeSortAndCount(list, sorted, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);

    printf("\nNumber of inversions: %d\n", inversionCount);

    return 0;
}
