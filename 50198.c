#include<stdio.h>
int countit(int x)
{
    int temp[50] = {}, ans = 0;
    for(int p=0 ; p<50 ; p++)
        temp[p] = -1;
    while(x != 0){
        int haha = x % 10, shit = ans;
        for(int p=0 ; p<=shit ; p++){
            if(haha == temp[p])break;
            if(p == ans){
                temp[p] = haha;
                ans++;
                //printf("%d ", haha);
            }
        }
        x /= 10;
        if(ans > 2)return 3;
    }
    return ans;
}

int main()
{
    int a, b, x;
    while(scanf("%d%d%d", &a, &b, &x) != EOF){
        while(countit(x)>2){
            x = (a * x) % b;
        }
        printf("%d\n", x);
    }
    return 0;
}