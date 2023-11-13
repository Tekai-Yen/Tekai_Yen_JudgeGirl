#include<stdio.h>

int main()
{
    int n, temp, count = 0, first = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &temp);
        if(temp == 0){
            count++;
            continue;
        }
        else{
            if(first) printf(" ");
            else first = 1;
            printf("%d", temp);
        }
    }
    while(count--){
        if(first) printf(" ");
        else first = 1;
        printf("0");
    }
    return 0;
}