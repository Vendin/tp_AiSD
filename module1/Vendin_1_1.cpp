#include <stdio.h>

int main(void) {
  int N, i = 2, A, B;
  scanf("%d", &N);
  while (N % i) {
    i++;
  }
  if (N % i) {
    i = 1;
  }
  A = N / i;
  B = N - A;
  printf(" %d %d ", A, B);
  return 0;
  
}
