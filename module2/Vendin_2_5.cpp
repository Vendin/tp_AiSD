#include <iostream>
#define MAX_SIZE 25000000
#define CUTOFF 7
using namespace std;

void quicksort( int* array, int left, int right)
{
    int tmp;
    if(left >= right) return;
    int spivot = array[left];
    int bpivot = array[right];
    if(spivot > bpivot){
        swap(array[right], array[left]);
        swap(spivot, bpivot);
    }
    int l = left + 1;
    int g =  right - 1;
    for(int k = l; k <= g; k++){
        if(array[k] < spivot) {
            swap(array[k],array[l]);
            l++;
        }
        else if(array[k] > bpivot){
            while(array[g] > bpivot && k  < g){ --g;}
            swap(array[g], array[k]);
            --g;
            if(array[k] < spivot){
                swap(array[k], array[l]);
                l++;
            }
        }
    }
    --l;
    ++g;
    swap(array[left], array[l]);
    swap(array[right], array[g]);
    if (l - 1 - left > CUTOFF) { 
    	quicksort(array, left, l-1);
    }
    if (g - 2 - l > CUTOFF) {
        quicksort(array, l+1, g-1);
    }
    if (right - g - 1 > CUTOFF) {
        quicksort(array, g+1, right);
    }
}

int main() {
    int *array = new int[MAX_SIZE];
    int i = 0;
    while(1) {
    	cin >> array[i];
    	if(cin.eof()) break;
    	if(cin.fail()) break;
    	++i;
    }
    quicksort(array, 0, i);
    for (int j = 9; j <= i; j += 10 ) {
        cout << array[j] << ' ';
    }
    delete [] array;
    return 0;
}

