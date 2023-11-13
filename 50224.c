#include<stdio.h>
#include<math.h>

int cal(int n)
{
    int haha = 0;
    while(n != 0){
        haha += n % 10;
        n /= 10;
    }
    return haha;
}

int countdigit(int n)
{
    int x=0;
    while(n != 0){
        x++;
        n /= 10;
    }
    return x;
}

int main()
{
    int current, maxsum = 0, maxdigit = 100, ans = 0;
    while(scanf("%d", &current) != EOF){
        if(cal(current) > maxsum){
            ans = current;
            maxsum = cal(current);
            maxdigit = countdigit(current);
        }

        if(cal(current) == maxsum){
            if(countdigit(current) < maxdigit){
                ans = current;
                maxsum = cal(current);
                maxdigit = countdigit(current);
            }
            else if(countdigit(current) == maxdigit){
                if(current > ans){
                    ans = current;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}