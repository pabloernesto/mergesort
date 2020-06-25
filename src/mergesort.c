# include "mergesort.h"

void mergesort(const int *arr, int size) {
  // recursive call
  if (size > 1) {
    mergesort(arr, size / 2);
    mergesort(arr + size / 2, size - size / 2);
  }

  // merge
  int *a0 = arr;
  int * const a1 = arr + size / 2;
  int *b0 = arr + size / 2;
  int * const b1 = arr + size;

  while (a0 != a1 && b0 != b1) {
    if (*a0 <= *b0) {
      a0++;
    } else {
      // swap
      int tmp = *a0;
      *a0 = *b0;
      *b0 = tmp;

      a0++;
      b0++;
    }
  }
}
