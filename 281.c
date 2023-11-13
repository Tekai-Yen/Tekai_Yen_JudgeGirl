#include<stdio.h>
#define MAX 2147483647

int main()
{
    int temp;
    while(scanf("%d", &temp) != EOF){
        int count = 0;
        while(temp != 0){
            count += temp % 2;
            temp /= 2;
        }
        printf("%d\n", count);
    }
}