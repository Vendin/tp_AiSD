//
//  main.c
//  quicksort
//
//  Created by Dmitry on 21.11.14.
//  Copyright (c) 2014 Dmitry. All rights reserved.
//

#include "stdlib.h"
#include "stdio.h"
#define MAX_SIZE 25000000
#define CUTOFF 7
#define SIZE 262144
#define swap(a, b)				\
tmp = a;						\
a = b;						    \
b = tmp;                        \

void quicksort_dual_pivot( int* array, int left, int right)
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
            while(array[g] > bpivot && k  < g){
                
                g--;
            }
            
            swap(array[g], array[k]);
            g--;
            
            if(array[k] < spivot){
                
                swap(array[k], array[l]);
                l++;
                
            }
        }
        
    }
    
    l--;
    g++;
    
    swap(array[left], array[l]);
    
    swap(array[right], array[g]);
    
    if (l - 1 - left > CUTOFF) {
        quicksort_dual_pivot(array, left, l-1);
    }
    if (g - 2 - l > CUTOFF) {
        quicksort_dual_pivot(array, l+1, g-1);
    }
    if (right - g - 1 > CUTOFF) {
        quicksort_dual_pivot(array, g+1, right);
    }
}

int main() {
    int *array = (int*) malloc(MAX_SIZE * sizeof(int));
    
    
/*    int c;
    int d;
    int i = 0;
    for (int flag; ; ) {
        d = 0;
        flag = 0;
        for(; c > 47 && c < 58 ;) {
            d = (d << 1) + (d << 3) + c - 48;
            flag = 1;
            c = getchar_unlocked();
        }
        if (flag) {
            *(array + i) = d;
            i++;
        }
        if (c == EOF || c == '\n') {
            break;
        }
        c = getchar_unlocked();
    }
    i--;*/

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
                //break;
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
    quicksort_dual_pivot(array, 0, i);
    //quickSortR(array, i);
    int k;
    int len = i;
    for (int i = 1; i <= len; ++i) {
        int tmp =  array[i];
        for (k = i; k > 0 && tmp < array[k - 1]; --k) {
            array[k] = array[k - 1];
        }
        array[k] = tmp;
    }
    
    
    for (int j = 9; j <= i; j += 10 ) {
        printf("%d ",*(array + j));
    }
    //free(array);
    return 0;
}

