#include<stdio.h>
#include<math.h>

int main()
{
    int first, second,ans = 100000000;
    scanf("%d", &first);
    while(scanf("%d", &second) != EOF){
         int a = first, b = second;
         first = b;
        int asec = 0, bsec = 0;
        asec += a % 100;
        a /= 100;
        asec += 60 * (a % 100);
        a /= 100;
        asec += 3600 * a;

        bsec += b % 100;
        b /= 100;
        bsec += 60 * (b % 100);
        b /= 100;
        bsec += 3600 * b;

        if(abs(asec - bsec) < ans) ans = abs(asec - bsec);
        
    }

    printf("%d", ans);


    return 0;
}