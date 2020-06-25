# include "mergesort.h"

void mergesort(int *arr, int size) {
  // recursive call
  if (size > 1) {
    mergesort(arr, size / 2);
    mergesort(arr + size / 2, size - size / 2);
  }

  // merge
  int tmp[size / 2];
  for (int i = 0; i < size / 2; i++)
    tmp[i] = arr[i];
  
  int *a = tmp;
  int * const enda = tmp + size / 2;
  int *b = arr + size / 2;
  int * const endb = arr + size;

  for (int i = 0; i < size; i++) {
    if (a == enda) {
      arr[i] = *(b++);
    } else if (b == endb) {
      arr[i] = *(a++);
    } else {
      int **minptr = *a <= *b ? &a : &b;
      arr[i] = **minptr;
      (*minptr)++;
    }
  }
}
