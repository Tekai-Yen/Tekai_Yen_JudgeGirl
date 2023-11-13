#include<stdio.h>
//#define int long long
//#define d lld

int gcd(int a, int b){
    return (b?gcd(b,a%b):a);
}

int sol(int a, int b){
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    return a * b / gcd(a,b);
}

int main()
{
    int a[4];
    while(scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) != EOF){
        for(int p=0 ; p<4 ; p++)
            for(int q=p ; q<4 ; q++){
                if(a[p] < a[q]){
                    int temp = a[p];
                    a[p] = a[q];
                    a[q] = temp;
                }
            }
        //for(int p=0 ; p<4 ; p++)printf("%d ", a[p]);
        int current = a[0];
        for(int p=1 ; p<4 ; p++){
            current = sol(current, a[p]);
        }
        printf("%d\n", current / a[0]);
    }
    return 0;
}