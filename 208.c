#include<stdio.h>
#include<string.h>
#include<assert.h>

char trans(int a, char a1, char a2){
    if(a) return a1;
    else return a2; 
}

int main()
{
    int N, M, n, data[32], count = 0, lane = 0;
    char bit1, bit0;
    scanf("%d%d", &N, &M);
    getchar();
    scanf("%c", &bit1);
    getchar();
    scanf("%c", &bit0);
    //printf("%d:%d:%c:%c:\n\n\n", N, M, bit1, bit0);
    n = N * M;
    unsigned int number;
    while(1){
        scanf("%u", &number);
        for(int p=0; p<32; p++){
            data[31-p] = number % 2;
            number /= 2;
        }
        assert(number == 0);
        for(int p=0; p<32; p++){
            printf("%c", trans(data[p], bit1, bit0));
            lane++;
            count++;
            if(lane == N){
                lane = 0;
                printf("\n");
            }
            if(count >= n){
                //printf("\n");
                return 0;
            }
        }
    }
}