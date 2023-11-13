#include<stdio.h>

int main(){
    int count = 1, hehe, temp, n;
    while(scanf("%d", &n) != EOF){
        count = 1;
        scanf("%d", &temp);
        n--;
        while(n--){
            scanf("%d", &hehe);
            if(hehe != temp)count++;
            temp = hehe;
        }
        printf("%d\n", count);
    }
}