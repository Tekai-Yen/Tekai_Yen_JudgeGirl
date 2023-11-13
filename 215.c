#include <stdio.h>
 
int main()
{
    int all,leg,tail;
    scanf("%d%d%d",&all,&leg,&tail);
    int a,b,c;
    c=all-tail;
    leg-=8*c;
    all-=c;
    if((leg-2*all)%2 == 0)
        b=(leg-2*all)/2;
    else{
        printf("0");
        return 0;
    }
    a=all-b;

    if(a<0 || b<0 || c<0){
        printf("0");
        return 0;
    }
    printf("%d\n%d\n%d\n",a,b,c);
 
}