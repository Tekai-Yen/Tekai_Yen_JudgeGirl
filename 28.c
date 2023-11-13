#include<stdio.h>

int haha(int n){
    if(n==1)return 1;
    else return n*n + haha(n-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", haha(n));
    return 0;
}