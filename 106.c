#include<stdio.h>
#include<stdbool.h>

int main()
{
    char data[1005];
    int num[1005];
    while(scanf("%s", &data)){
        if(data[0] == '-')
            break;
        int n = 0, even = 0, odd = 0, ptr = 0;
        while(data[n] != '\0'){
            num[n] = data[n] - '0';
            n++;
        }
        while(ptr < n){
            even += num[ptr];
            ptr += 2;
        }
        ptr = 1;
        while(ptr < n){
            odd += num[ptr];
            ptr += 2;
        }
        printf("%s ", (num[n-1]%2 == 0)?"yes":"no");
        printf("%s ", ((even + odd)%3 == 0)?"yes":"no");
        printf("%s ", (num[n-1] == 0 || num[n-1] == 5)?"yes":"no");
        printf("%s\n", ((even-odd)%11 == 0)?"yes":"no");
    }
    return 0;
}