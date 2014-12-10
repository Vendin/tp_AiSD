#include <iostream>

int binary(int *A, int n, int k) {
	int left = 0, right = n, mid;
  while (left <= right) {
  	mid = left + (right - left) / 2;
		if (k < A[mid]) {
			if((k <= A[mid] && k > A[mid-1]) || (k < A[mid] && mid == 0)) { return mid; }
		 right = mid - 1;
    } else {
    	if (k > A[mid]) {
        if(k >= A[mid] && k < A[mid-1]) {
		    	return mid;
		    }
		    left=mid+1;
      } else { return mid; }
		}
	}
  return n;
}

int main() {
  int *A, *B, n, m;
  std::cin >> n >> m;
  A = new int[n];
  B = new int[m];
  for (int j = 0; j < n; j++) {
    std::cin >> A[j];
  }
  for (int j = 0; j < m; j++) {
    std::cin >> B[j];
  }
  for (int v = 0; v < m; v++) {
    std::cout << " " << binary(A,n,B[v]);
  }
  std::cout << std::endl;
  return 0;
}

