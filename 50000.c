#include<stdio.h>

int main()
{
    long long int k, current, cnt = 0, length = 0, ans = 0;
    scanf("%d", &k);
    _Bool positive = 1;

    while(scanf("%d", &current) != EOF){
        if(current == 0){
            //if(length > ans && cnt == 0)
            //    ans = length;
            break;
        }
        if(positive){
            if(current < 0){//違反規定
                if(length > ans && cnt == 0)
                    ans = length; 
                positive = 1;
                cnt = 0;
                length = 0;
                continue;
            }
        
            cnt++;//正確
            if(cnt == k){
                positive = 0;
                cnt = 0;
                length += k;
                if(length > ans && cnt == 0)
                    ans = length; 
            }
        }
        else{
            if(current > 0){//違反規定
                if(length > ans && cnt == 0)
                    ans = length;
                length = 1;
                positive = 1;
                cnt = 1;
                if(cnt == k){
                    positive = 0;
                    cnt = 0;
                }
                continue;
            }

            cnt++;//正確
            if(cnt == k){
                positive = 1;
                cnt = 0;
                length += k;
                if(length > ans && cnt == 0)
                    ans = length; 
            }
        }
    }
    if(ans < 3*k){
        printf("0");
        return 0;
    }
    if((ans/k)%2 == 0) ans -= k;
    printf("%d", ans);
    return 0;
}

//答案必定大於等於3k