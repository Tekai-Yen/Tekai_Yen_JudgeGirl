#include<stdio.h>
#define PI 3.1415926

int main()
{
    double a, b, c, ans = 0.0, temp;
    scanf("%lf%lf%lf", &a, &b, &c);
    ans = ans + 0.75*PI*c*c;
    ans += (c>b)?0.25*PI*(c-b)*(c-b):0;
    ans += (c>a)?0.25*PI*(c-a)*(c-a):0;
    printf("%lf", ans);
    return 0;
}