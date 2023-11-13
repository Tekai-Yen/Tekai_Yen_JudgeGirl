#include<stdio.h>

int tekai(int r, int c){
    //printf("%d %d\n", r, c);
    if(r == 0 || c == 0) return 1;
    else return tekai(r-1, c) + tekai(r, c-1);
}

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    printf("%d", tekai(r-1, c-1));
    return 0;
}