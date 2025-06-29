def merge(list, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = [0] * n1
    R = [0] * n2

    for i in range(0, n1):
        L[i] = list[left + i]

    for j in range(0, n2):
        R[j] = list[mid + 1 + j]

    i = 0
    j = 0
    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            list[k] = L[i]
            i += 1
        else:
            list[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        list[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        list[k] = R[j]
        j += 1
        k += 1


def mergeSort(list, left, right):
    if left < right:
        mid = (left + right) // 2

        mergeSort(list, left, mid)
        mergeSort(list, mid + 1, right)
        merge(list, left, mid, right)


list = [34, 7, 23, 32, 5, 62]
mergeSort(list, 0, len(list) - 1)
print("Sorted array is:", list)
