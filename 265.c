#include<stdio.h>

int main()
{
    int up = -1000000, down = 1000000, left = 1000000, right = -1000000, x, y;
    while(scanf("%d%d", &x, &y) != EOF){
        if(x > right) right = x;
        if(x < left) left = x;
        if(y > up) up = y;
        if(y < down) down = y;
    }
    printf("%d", (up - down) * (right - left));
    return 0;
}