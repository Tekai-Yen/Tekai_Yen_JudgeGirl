#include<stdio.h>
int countdigit(int a){
    int haha = 0;
    while(a){
        haha++;
        a /= 10;
    }
    return haha;
}

int main()
{
    int k, L;
    scanf("%d%d", &k, &L);
    int temp, current = 0;
    while(scanf("%d", &temp) != EOF){
        if(temp == 0)break;
        int times = temp % k;
        if(current + times * countdigit(temp) <= L){
            current += times * countdigit(temp);
            for(int p=1 ; p<=times ; p++){
                printf("%d", temp);
            }
        }
        else{
            if(times * countdigit(temp) <= L){
                printf("\n");
                current = times * countdigit(temp);
                for(int p=1 ; p<=times ; p++){
                    printf("%d", temp);
                }
            }
            else continue;
        }
    }
    return 0;
}