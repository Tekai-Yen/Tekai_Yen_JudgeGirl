#include<stdio.h>

int main()
{
    int data;
    while(scanf("%d", &data) != EOF){
        printf("%d ", data/1000);
        data %= 1000;
        printf("%d ", data/500);
        data %= 500;
        printf("%d ", data/100);
        data %= 100;
        printf("%d ", data/50);
        data %= 50;
        printf("%d ", data/10);
        data %= 10;
        printf("%d ", data/5);
        data %= 5;
        printf("%d\n", data);
    }
    return 0;
}