#include<stdio.h>

int main()
{
    int ans = 0, temp;
    while(scanf("%d", &temp) != EOF){
        ans += temp;
    }
    printf("%d", ans);
}