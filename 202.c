#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int gcd(int a, int b)
{
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    while(b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int A1, A2 = c, B1, B2 = g, C1, C2;
    if(a < 0) A1 = -(b - a*c);
    else A1 = b + a*c;
    if(e < 0) B1 = -(f - e*g);
    else B1 = f + e*g;
    switch(d){
        case 0:
            C2 = A2 * B2 / gcd(A2, B2);//printf("C2 = %d\n", C2);//通分
            A1 *= (C2/A2);//printf("A1 = %d\n", A1);
            B1 *= (C2/B2);//printf("B1 = %d\n", B1);
            C1 = A1 + B1;//printf("C1 = %d\n", C1);
            if(gcd(C1, C2) != 1){
                int k = gcd(C1, C2);
                C1 /= k;
                C2 /= k;
            }
            //printf("\nC1 = %d C2 = %d\n\n", C1, C2);

            break;
        case 1:
            C2 = A2 * B2 / gcd(A2, B2);//通分
            A1 *= (C2/A2);
            B1 *= (C2/B2);
            C1 = A1 - B1;
            if(gcd(C1, C2) != 1){
                int k = gcd(C1, C2);
                C1 /= k;
                C2 /= k;
            }
            break;

        case 2:
            C1 = A1 * B1;
            C2 = A2 * B2;
            if(gcd(C1, C2) != 1){
                int k = gcd(C1, C2);
                C1 /= k;
                C2 /= k;
            }
            break;
        case 3:
            C1 = A1 * B2;
            C2 = A2 * B1;
            if(gcd(C1, C2) != 1){
                int k = gcd(C1, C2);
                C1 /= k;
                C2 /= k;
            }
            break;
    }
    /*if(C1 < 0){
        printf("-");
        C1 = -C1;
    }*/
    printf("%d\n", C1/C2);
    C1 %= C2;
    printf("%d\n",abs(C1));
    if(C1)printf("%d", abs(C2));
    else printf("1");
    return 0;
}