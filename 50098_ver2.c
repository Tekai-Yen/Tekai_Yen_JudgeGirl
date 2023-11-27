#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 150

void calculate(int N, int K, int answersheet[], int count, long long int check, int current, long long int data[]){
    //assert(current <= N);
    if(count == K){
        for(int p=0; p<K; p++){
            printf("%d\n", answersheet[p]);
        }
        exit(0);
    }
    if(current >= N) return;
    if((data[current] & check) != 0){
        //printf("FFF\n");
        calculate(N, K, answersheet, count, check, current+1, data);
        return;
    }
    
    answersheet[count] = current;
    calculate(N, K, answersheet, count+1, (check | data[current]), current+1, data);
    calculate(N, K, answersheet, count, check, current+1, data);
}

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    int answersheet[MAX];
    long long int data[MAX];
    for(int p=0; p<N; p++){data[p] = 0; answersheet[p] = -1;}
    for(int p=0; p<N; p++){
        int times;
        scanf("%d", &times);
        while(times--){
            int temp;
            scanf("%d", &temp);
            data[p] += ((long long int)1 << temp);
        }
        //printf("%d: %lld\n", p, data[p]);
    }
    for(int p=0; p<N-K; p++) calculate(N, K, answersheet, 0, 0ll, p, data);
    return 0;
}