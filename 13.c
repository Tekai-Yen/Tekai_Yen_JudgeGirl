#include<stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    for(int p=1 ; p<=x ; p++)
        for(int q=1 ; q<=p ; q++)  
            printf("%d", q);
    return 0;
}