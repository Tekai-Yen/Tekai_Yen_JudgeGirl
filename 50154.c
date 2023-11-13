#include<stdio.h>
 
int main()
{
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    printf("%d\n%d", a+b+c+d+a*e+b*e+c*e+c*f+d*f+e*g+g+f, (a*e+b*e+c*e)*g+(c*f+d*f));
    return 0;
}