#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
  const int MAX = 10000;
  bool arr[MAX];
  arr[0] = false; 
  arr[1] = false;
  for (int i = 2; i < MAX; i++) {
    arr[i] = true;
  }
  for (int i = 2; i*i <= MAX; i++) {
    for ( int j = i+1; j < MAX; j++) {
      if (j % i == 0) {
        arr[j] = false;
      }
    }
  }
  for (int i = 0; i < MAX; i++) {
    if (arr[i] == true) {
      printf("%i ", i);
    }
  }
  printf("\n");
  return 0;
}

/* tbh i hacked this together before i saw the problem specification...
 * this is better in my opinion :)
typedef struct isPrime {
  int val;
  int type;
} isPrime_t;

int* sieve(int max);
void freeArr(isPrime_t *arr, int size);

int main(void) {
  int max = 10000;
  int* s = sieve(max);
  for (int i = 0; s[i] != 0; i++) {
    printf("%i ", s[i]);
  }
  printf("\n");
  free(s);
  return 0;
}

int* sieve(int max) {
  // init arr up to max
  int count = max-2;
  isPrime_t *arr = (isPrime_t*) malloc(sizeof(isPrime_t) * (max-2));
  if (!arr) {
    printf("malloc failed at init of array\n");
    exit(0);
  }
  for (int i = 2; i <= max-2;i++) {
    arr[i].val = i;
    arr[i].type = 1;
  }

  // set the isPrime.type to 0 if not a prime
  for (int i = 0; i <= max; i++) {
    for (int j = (i+1); j <= max; j++) {
      if (arr[j].type == 1 && arr[i].val != 0) {
        if (arr[j].val % arr[i].val == 0) {
          arr[j].type = 0;
          count--;
        }
        else continue;
      }
    }
  }
  int *ret = (int*) malloc(sizeof(int)*count);
  if (!ret) {
    printf("malloc failed at init of return array\n");
    exit(0);
  }
  int j = 0;
  for (int i = 0; i < max;i++) {
    if (arr[i].type == 1) {
      ret[j] = arr[i].val;
      j++;
    }
  }
  free(arr);
  return ret;
}
*/
