#include<stdio.h>

int LSB(int a){
    return a%10;
}
int MSB(int a){
    while(a >= 10)
        a /= 10;
    return a;
}
int len(int a){
    int cnt = 0;
    while(a != 0){
        a /= 10;
        cnt++;
    }
    return cnt;
}

int main()
{
    int temp, current, ans = 0, haha = 0;
    scanf("%d", &temp);
    ans = haha = len(temp);
    while(scanf("%d", &current) != EOF){
        int g = len(current);
        if(LSB(temp) == MSB(current)){
            haha += g;
        }
        else{
            haha = g;
        }
        temp = current;
        ans = haha>ans ? haha : ans;
    }
    printf("%d", ans);
    return 0;
}