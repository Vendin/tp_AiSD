#include <iostream>
#include <cstring>
using namespace std;

void vivod(int *arr, int n) {
  for ( int i = 0; i < n; ++i ) {
    cout << arr[i];
    if ( i != n-1 ) {
      cout << '\n';
    }
  }
}

void sort_vstavka(int *arr, int n) {
  int j;
  for ( int i = 1; i < n; ++i ) {
    int temp = arr[i];
    for ( j = i; j > 0 && temp < arr[j-1]; --j ) {
      arr[j] = arr[j-1];
    }
    arr[j] = temp;
    }
  }
int main() {
  int raz = 32, i = -1;
  int *mas = new int[raz];
  while (1) {
    ++i;
    if ( i % 32 == 0 && i != 0 ) {
      raz += 32;
      int *mas1 = new int[raz];
      for ( int q = 0; q < raz-32; ++q ) {
        mas1[q] = mas[q];
      }
      delete [] mas;
      mas = mas1;
    }
    cin >> mas[i];
    if (cin.fail()) break;
    if (cin.eof()) break;
  }
  sort_vstavka(mas, i);
  vivod(mas, i);
  return 0;
}

