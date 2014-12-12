//programming language C
#include "stdlib.h"
#include "stdio.h"
#define MAX_SIZE 25000000 //maximum size on a condition
#define SIZE 262144 //=2^18

void QuickSort (int Ar[], long N) {
    long i=0, j=N;
    int  temp, p;
    p=Ar[N/2];
    do
    {
        while(Ar[i]<p) i++;
        while (Ar[j]>p) j--;
        if(i<=j)
        {
            temp = Ar[i];
            Ar[i]=Ar[j];
            Ar[j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>0) QuickSort(Ar, j);
    if(N>i) QuickSort(Ar+i, N-i);
}

int main() {
    int *array = (int*) malloc(MAX_SIZE * sizeof(int));
    char buffer[SIZE];
    int input = 0;
    int i = 0, j = 0;
    size_t c;
    int flag = 0;
    while ((c = fread (buffer, sizeof (char), SIZE, stdin)) > 0 )
    {
        for (j = 0; j < c; j++)
        {
            if (buffer[j] == ' ')
            {
                if (flag) {
                    array[i++] = input;
                    input = 0;
                }
                flag = 0;
                input = 0;
            }
            else if (buffer[j] == '\n') {
                break;
            }
            else if (buffer[j] == EOF) {
                break;
            }
            else
            {
                input = (input * 10) + (buffer[j] - '0');
                flag = 1;
            }
        }
        if (buffer[j] == '\n' || buffer[j] == EOF) {
            break;
        }
    }
    if (input) {
        array[i] = input;
    }
    else i--;

    QuickSort(array, i);
    int h;
    for (h = 9; h <= i; h += 10 ) {
        printf("%d ",*(array + h));
    }
    return 0;
}

