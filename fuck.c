
#include <stdio.h>


void print(int x){
    printf("Not(in=sel[0], out=notsel0);\nNot(in=sel[1], out=notsel1);\nAnd(a=a[%d], b=notsel0, out=q);\nAnd(a=q, b=notsel1, out=A);\nAnd(a=b[%d], b=notsel1, out=w);\nAnd(a=w, b=sel[0], out=B);\nAnd(a=c[%d], b=sel[1], out=e);\nAnd(a=e, b=notsel0, out=C);\nAnd(a=d[%d], b=sel[0], out=r);\nAnd(a=r, b=sel[1], out=D);\nOr(a=A, b=B, out=X);\nOr(a=C, b=D, out=Y);\nOr(a=X, b=Y, out=out);\n\n",x,x,x,x);
}

int main()
{
    for(int p=0 ; p<=15 ; p++)
        print(p);
    return 0;
}
