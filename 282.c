#include<stdio.h>
#define MAX 2147483647
#define int unsigned long long
signed main()
{
    int temp;
    while(scanf("%lld", &temp) != EOF){
        int count = 0;
        while(temp != 0){
            count += temp % 2;
            temp /= 2;
        }
        printf("%lld\n", count);
    }
}