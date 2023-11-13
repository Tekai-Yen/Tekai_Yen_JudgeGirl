#include<stdio.h>

int main()
{
    int temp;
    while(scanf("%d", &temp) != EOF){
        int count = 0, ans = 0;
        while(temp != 0){
            if(temp%2){
                count++;
            }
            else{
                count = 0;
            }
            ans = (count>ans)?count:ans;
            temp /= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}