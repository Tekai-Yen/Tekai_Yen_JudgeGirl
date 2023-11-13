#include<stdio.h>

int main()
{
    int a, b, A=0, B=0;
    scanf("%d%d", &a, &b);
    int x[4], y[4];
    for(int p=0 ; p<4 ; p++){
        x[p] = a % 10;
        y[p] = b % 10;
        a /= 10;
        b /= 10;
    }
    for(int p=0 ; p<4 ; p++)
        for(int q=0 ; q<4 ; q++){
            if(x[p] == y[q]){
                if(p == q)A++;
                else B++;
            }
        }
    printf("%dA%dB", A, B);
    return 0;
}