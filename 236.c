#include<stdio.h>

void swap(int* a, int* b){
    int haha = *a;
    *a = *b;
    *b = haha;
}

int gcd(int a, int b){
    return b==0? a : gcd(b, a%b);
}

int main()
{
    int current,temp;
    scanf("%d", &current);
    while(scanf("%d", &temp) != EOF){
        if(current < temp) swap(&current, &temp);
        current = current * temp / gcd(current, temp);
    }
    printf("%d", current);
    return 0;
}