#include <stdio.h>

int result(int a[], int n, int low, int high, int key)
{
    int i, j, temp, mid;
    // Bubble sort
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // Binary search
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, i, key, a[100], ans;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    ans = result(a, n, 0, n-1, key);
    if (ans == -1)
        printf("Not found\n");
    else
        printf("Key found at index %d\n", ans);
    return 0;
}
