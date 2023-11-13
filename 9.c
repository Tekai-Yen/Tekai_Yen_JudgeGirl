#include<stdio.h>

int main()
{
    int score = 0;
    int x;
    scanf("%d", &x);
    if(x <= 0 ){
        printf("-100");
        return 0;
    }
    else{
        score += (x%3==0 ?3:0);
        score += (x%5==0?5:0);
        score += ((x>=100 && x<=200) ?50:-50);
        printf("%d", score);
    }

    return 0;
}