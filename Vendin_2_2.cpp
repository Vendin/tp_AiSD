#include <iostream>
using namespace std;

struct box {
  int x, y, z, number;
  box() {}
  void definition(int n) { number = n; cin >> x >> y >> z; }
  void sort_3();
  friend bool operator < (box B1, box B2);
  friend bool operator > (box B1, box B2);
  template <class X> friend void heap_insert(X *a, int n, X x);
  template <class X> friend void heap_pop(X *a, int n);
  template <class X> friend void heap_sort(X *data, int n);
};

void box::sort_3() {
  int *v = new int[3];
  v[0] = x; v[1] = y; v[2] = z;
  heap_sort(v, 3);
  x = v[0]; y = v[1]; z = v[2];
  delete [] v;
}

bool operator < (box B1, box B2) {
  if ( B1.x < B2.x && B1.y < B2.y && B1.z < B2.z ) { return true; }
  return false;
}

bool operator > (box B1, box B2) {
  if ( B1.x > B2.x && B1.y > B2.y && B1.z > B2.z ) { return true; }
  return false;
}

template <class X> void heap_pop(X *a, int n) {
  swap(a[n], a[1]);
  for (int i = 1; 2*i < n;) {
    i *= 2;
    if (i+1 < n && a[i] < a[i+1]) {
      i += 1;
    }
    if (a[i/2] < a[i]) {
     swap(a[i/2], a[i]);
    }
  }
}

template <class X> void heap_insert(X *a, int n, X x) {
  a[n+1] = x;
  for (int i = n+1; i > 1;) {
    if (a[i] > a[i/2]) {
      swap(a[i], a[i/2]);
      i = i/2;
    } else {
      break;
    }
  }
}

template <class X> void heap_sort(X *data, int n) {
  X *buff = new X[n+1];
  for (int i = 0; i < n; ++i) {
    heap_insert(buff, i, data[i]);
  }
  for (int i = 0; i < n; ++i) {
    data[n-1-i] = buff[1];
    heap_pop(buff, n-i);
  }
  delete [] buff;
}

int main() {
  int amount;
  cin >> amount;
  box *Bx = new box[amount];
  for (int i = 0; i < amount; ++i) {
      Bx[i].definition(i);
      Bx[i].sort_3();
    }
  heap_sort(Bx, amount);
   for (int i = 0; i < amount; ++i) {
    cout << Bx[i].number << " ";
  }
  delete [] Bx;
  return 0;
}
