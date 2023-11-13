#include<stdio.h>

int main()
{
    int a, b, ans=1;
    scanf("%d%d", &a, &b);
    for(int p=1 ; p<=b ; p++)
        ans *= a;
    printf("%d", ans);
    return 0;
}