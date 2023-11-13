#include<stdio.h>
 
int subset(int a, int b, int k, int data[]){
    if(a > b) return 0;
    if(k == data[a]) return 1;
    else if(k < data[a]) return 0;
    else return subset(a+1, b, k-data[a], data) + subset(a+1, b, k, data);
}
 
int main()
{
    int N, data[15], k;
    scanf("%d", &N);
    for(int p=0; p<N; p++){
        scanf("%d", &data[p]);
    }
    for(int p=N-2; p>=0; p--){//sort 遞增
        for(int q=0; q<=p; q++){
            if(data[q] > data[q+1]){
                int temp = data[q+1];
                data[q+1] = data[q];
                data[q] = temp;
            }
        }
    }
 
    while(scanf("%d", &k) != EOF){
        printf("%d\n", subset(0, N-1, k, data));
    }
    return 0;
}