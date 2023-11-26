#include<stdio.h>

void mergesort(int data[], int l, int r){
    int number = r-l+1;
    for(int p=l; p<=r; p++){
        printf("%d", data[p]);
        if(p != r) printf(" ");
    }
    printf("\n");
    if(number == 1) return;
    mergesort(data, l, l+number/2-1);
    mergesort(data, l+number/2, r);
    int ptra = l, ptrb = l + number/2, temp[number];
    for(int p=0; p<number; p++){
        if(ptra > l+number/2-1){
            temp[p] = data[ptrb];
            ptrb++;
            continue;
        }
        if(ptrb > r){
            temp[p] = data[ptra];
            ptra++;
            continue;
        }
        if(data[ptra] < data[ptrb]){
            temp[p] = data[ptra];
            ptra++;
        }
        else {//if(data[ptra] > data[ptrb]){
            temp[p] = data[ptrb];
            ptrb++;
        }
    }
    for(int p=0; p<number; p++){
        printf("%d", temp[p]);
        if(p != number-1) printf(" ");
        data[l+p] = temp[p];
    }
    printf("\n");
    
}

int main()
{
    int N = 0, data[100050];
    while(scanf("%d", &data[N]) != EOF){N++;}
    mergesort(data, 0, N-1);
    return 0;
}