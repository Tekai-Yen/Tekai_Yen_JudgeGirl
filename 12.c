#include<stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    for(int p=1 ; p<=x ; p++)printf("%d\n", p);
    for(int p=x-1 ; p>=1 ; p--)printf("%d\n", p);


    return 0;
}