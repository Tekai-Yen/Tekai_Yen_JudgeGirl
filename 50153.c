#include<stdio.h>

int main()
{
    int a, b, c, d, e, f, x = 0, y = 0;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    x = 2 * (a+b+c+d+e+f);
    y = (a+c+e) * (b+d+f) - b * (c+e) - d*e;
    printf("%d\n%d", x, y);
    return 0;
}