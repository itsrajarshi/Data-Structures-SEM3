#include <stdio.h>

#define SWAP(x, y, t) { t = x; x = y; y = t; }

void quicksort(int list[], int left, int right) {
    int pivot, i, j, temp;
    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            while (list[i] <= list[pivot] && i < right)
                i++;
            while (list[j] > list[pivot])
                j--;
            if (i < j) {
                SWAP(list[i], list[j], temp);
            }
        }
        SWAP(list[pivot], list[j], temp);
        quicksort(list, left, j - 1);
        quicksort(list, j + 1, right);
    }
}

int main() {
    int list[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(list) / sizeof(list[0]);
    quicksort(list, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    return 0;
}