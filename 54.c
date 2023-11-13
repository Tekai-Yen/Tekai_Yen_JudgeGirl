#include<stdio.h>

int main()
{
    int n, m, a1, a2, b1 = 100, b2 = 100, count = 0;
    scanf("%d%d", &n, &m);
    a2 = n % 10;
    n /= 10;
    a1 = n;
    b2 = m % 10;
    m /= 10;
    while(m != 0){
        b1 = b2;
        b2 = m % 10;
        if(a2 == b1 && a1 == b2)count++;
        m /= 10;
    }
    printf("%d", count);
    return 0;
}