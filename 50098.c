#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 100

void print(int answersheet[], int K){
    for(int p=0; p<K; p++)
        printf("%d\n", answersheet[p]);
}

void findit(int answersheet[], int N, int K, int count, bool check[MAX][MAX], int current){
    //printf("%d\n", count);
    if(current >= N) return;
    for(int p=0; p<count; p++)
        if(!check[answersheet[p]][current]){
            findit(answersheet, N, K, count, check, current+1);
            return;
        }
    answersheet[count] = current;
    count++;
    if(count == K){
        print(answersheet, K);
        exit(0);
    }
    for(int p=current+1; p<N; p++){
        findit(answersheet, N, K, count+1, check, p);
        findit(answersheet, N, K, count, check, p);
    }
}


int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    int answersheet[MAX];
    long long int data[70];
    bool check[MAX][MAX];
    for(int p=0; p<N; p++){data[p] = 0; answersheet[p] = -1;}
    for(int p=0; p<N; p++){
        int times;
        scanf("%d", &times);
        while(times--){
            int temp;
            scanf("%d", &temp);
            data[p] += ((long long int)1 << temp);
        }
        // printf("%d: %lld\n", p, data[p]);
    }

    //for(int p=0; p<N; p++)
        //for(int q=0; q<N; q++)
            //check[p][q] = 0;

    for(int p=0; p<N-1; p++)
        for(int q=p+1; q<N; q++){
            //printf("data[%d] = %lld, data[%d] = %lld, a&b = %d\n", p, data[p], q, data[q], data[p] & data[q]);
            check[p][q] = check[q][p] = ((data[p] & data[q]) == 0)? 1ull : 0ull;//disjoint -> true
        }
            

    for(int p=0; p<N; p++){
        for(int q=0; q<N; q++){
            //printf("%d ", check[p][q]);
        }
        //printf("\n");
    }
    for(int p=0; p<N; p++) findit(answersheet, N, K, 0, check, p);
    return 0;
}