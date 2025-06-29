#include <stdio.h>
#include <string.h>

// binary search
int binarysearch(char *arr[], int size, char *key, char *midvalues[],
                 int *midcount) {
  int low = 0, high = size - 1;
  *midcount = 0;

  while (low <= high) {
    int mid = (low + high) / 2;

    midvalues[*midcount] = arr[mid];
    (*midcount)++;

    int cmp = strcmp(arr[mid], key);

    if (cmp == 0)
      return mid;
    else if (cmp < 0)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

// main
int main() {
  char *arr[] = {"babka",     "baklava",     "cheesecake", "cupcake",
                 "danish",    "eclair",      "funnelcake", "kringle",
                 "lamington", "profiterole", "sopaipilla", "strudel",
                 "tiramisu",  "torte",       "turnover"};
  int size = sizeof(arr) / sizeof(arr[0]);

  char *key = "doughnut";
  printf("searching for %s\n", key);

  char *midvalues[size];
  int midcount;

  int result = binarysearch(arr, size, key, midvalues, &midcount);

  if (result != -1)
    printf(" '%s' found at index %d\n", key, result);
  else
    printf("'%s' not found\n", key);

  printf("Mid values encountered during the search:\n");
  for (int i = 0; i < midcount; i++)
    printf("%s\n", midvalues[i]);
  return 0;
}