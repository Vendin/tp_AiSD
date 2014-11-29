#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int partition(int *mas, int l, int r) {
  if (l!=r)
    swap(mas[l + rand() % (r - l)], mas[r]);
  int x = mas[r];
  int i = l-1;
  for (int j = l; j <= r; j++) {
    if (mas[j] <= x)
      swap(mas[++i],mas[j]);
  }
  return i;
}
int order_statistics(int *mas, int n, int k) {
  int l = 0, r = k - 1;
  for(;;) {
    int pos = partition(mas,l,r);
    if (pos < n)
      l = pos + 1;
    else if (pos > n)
      r = pos - 1;
    else return mas[n];
  }
}

int main (void) {
  srand(time(NULL));
  int n, k;
  cin >> n >> k;
  int *mas = new int[n];
  for(int i = 0; i < n; ++i) {
    cin >> mas[i];
  }
 cout << order_statistics(mas, k, n);
  
  return 0;
}