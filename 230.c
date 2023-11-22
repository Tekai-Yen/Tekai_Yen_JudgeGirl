#include<stdio.h>

int max(int a, int b){return a>b?a:b;}

int tekai(int data[20][2], int W, int N, int current, int countweight, int value){
    if(countweight > W) return value - data[current-1][1];
    if(current == N-1){
        if(countweight + data[current][0] <=W) return value + data[current][1];
        else return value;
    }
    return max(tekai(data, W, N, current+1, countweight+data[current][0], value+data[current][1]), tekai(data, W, N, current+1, countweight, value));
}

int main()
{
    int N, W, data[20][2];
    scanf("%d%d", &N, &W);
    for(int p=0; p<N; p++) scanf("%d%d", &data[p][0], &data[p][1]);
    printf("%d\n", tekai(data, W, N, 0, 0, 0));
    return 0;
}