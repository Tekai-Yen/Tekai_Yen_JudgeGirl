#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int a=1 ; a<=9 ; a++)
        for(int b=((a-n)<0?0:a-n) ; b<=((a+n)>9?9:a+n) ; b++)
            for(int c=((b-n)<0?0:b-n) ; c<=(b+n>9?9:b+n) ; c++)
                for(int d=((c-n)<0?0:c-n) ; d<=(c+n>9?9:c+n) ; d++)
                    printf("%d%d%d%d\n", a, b, c, d);
    return 0;
}