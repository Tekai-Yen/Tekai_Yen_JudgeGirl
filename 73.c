#include<stdio.h>

int main()
{
    int n, a=0, b=0, c=0;
    scanf("%d", &n);
    while(n--){
        int temp;
        scanf("%d", &temp);
        if(temp%3 == 0)a++;
        if(temp%3 == 1)b++;
        if(temp%3 == 2)c++;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}