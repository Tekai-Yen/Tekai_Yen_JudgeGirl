#include<stdio.h>

int main()
{
    int x[4], y[4], l = 0, a = 0;
    for(int p=0 ; p<4 ; p++)
        scanf("%d%d", &x[p], &y[p]);
    l = 2 * (x[2] + y[2] - x[0] - y[0]);
    a = (x[2] - x[0]) * (y[2] - y[0]) - (x[2] - x[1]) * (y[1] - y[0]) - (x[3] - x[0]) * (y[2] - y[3]);
    printf("%d\n%d", l, a);
    return 0;
}