#include <stdio.h>

void fill_array(int *ptr[], int n){
    int *const front = ptr[0], *const rear = ptr[n-1], *temp = ptr[0];
    for(int *p=front; p!=rear; p++)
        *p = -1;
    for(int p=0; p<n; p++)
        *ptr[p] = p;
    for(int *p=front+1; p!=rear+1; p++){
        if(*p != -1){
            int value = *temp + *p;
            for(int *q=temp+1; q!=p; q++)
                *q = value;
            temp = p;
        }
    }
}

int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}