#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//--- Сортировка выбором -----------------------------------
template <typename X> void selection_sort(X *arr, int n) { 
	for (int i = 0; i < n -1; ++i) {
		int min_index = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min_index]) min_index = j;
		}
		swap(arr[i], arr[min_index]);
	}
}

//--- Сортировка вставками ----------------------------------
template <typename X> void insertion_sort(X *arr, int n) {
	int j;
	for (int i = 1; i < n; ++i) {
		X tmp = arr[i];
		for ( j = i; j > 0 && tmp < arr[j - 1]; --j) {
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}



//--- Сортировка Пузырьком ----------------------------------
template <typename X> void bubble_sort(X *arr, int n) { 
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}



 // --- Пирамидальная сортировка ----------------------------

template <typename X> void heap_pop(X *arr, int n) {
	swap(arr[n], arr[1]);
	for (int i = 1; 2*i < n;){
		i *= 2;
		if (i+1 < n && arr[i] < arr[i+1]){
			i += 1;
		}
		if (arr[i/2] < arr[i]) {
			swap(arr[i/2], arr[i]);
		}
	}
}

template <typename X> void heap_insert (X *arr, int n, X x) {
	arr[n+1] = x;
	for (int i =n+1; i > 1;) {
		if (arr[i] > arr[i/2]){
			swap(arr[i], arr[i/2]);
			i = i/2;
		} else {
			break;
		}
	}
}

template <typename X> void heap_sort(X *data, int n) {
	X *buff = new X[n + 1];
	for (int i = 0; i < n; ++i) {
		heap_insert(buff, i, data[i]);
	}
	for (int i =0; i < n; ++i) {
		data[n-1-i] = buff[1];
		heap_pop(buff, n - i);
	}
	delete [] buff;
}

//---Пирамидальная сортировка за линейное время

template <typename X> void heap_make(X *a, int n) {
	for (int i = n/2; i >= 1; --i) {
		for (int j = i; j <= n/2;) {
			int k = j*2;
			if (k+1 <= n && a[k] < a[k+1]) {
				++k;
			}
			if (a[j] < a[k]) {
				swap(a[k], a[j]);
				j = k;
			} else {
				break;
			}
		}
	}
}

template <typename X> void heap_sort_fast(X *data, int n) {
	heap_make(data - 1, n);
	for (int i = 0; i < n; ++i) {
		heap_pop(data - 1, n - i);
	}
}

//--- Гномья сортировка --------------------------

template <typename X> void Gnome_sort(X *arr, int n) {
	int i = 0;
	while(i < n) {
		if (i == 0 || arr[i-1] <= arr[i]) ++i;
		else {
			swap(arr[i], arr[i-1]);
			--i;
		}
	}
}
int main(void) {
	srand(time(NULL));
	int n;
	cin >> n;
	int *mas = new int[n];
	cout << endl;
	for(int i = 0; i < n; ++i) {
		mas[i] = rand() % 1000;
		cout << " " << mas[i];
	}
	cout << endl;
	heap_sort(mas, n);
	for(int i = 0; i < n; ++i) {
		cout << " " << mas[i];
	}
	cout << endl;
	return 0;
}
