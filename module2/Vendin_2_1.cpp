#include <iostream>
#include <cstring>
using namespace std;

void output(int *arr, int n) {
  for ( int i = 0; i < n; ++i ) {
    cout << arr[i];
    if ( i != n-1 ) {
      cout << '\n';
    }
  }
}

void sort_insert(int *arr, int n) {
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
  std::vector<int> mas;
  while (1) {
  	int value;
  	cin >> value;
  	if (cin.eof()) break;
  	if (cin.fail()) break;
  	mas.push_back(value);
  }
  sort_insert(mas, i);
  output(mas, i);
  return 0;
}

