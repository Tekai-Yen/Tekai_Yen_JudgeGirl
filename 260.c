#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main()
{
    char ans[10000], temp[10000];
    scanf("%s", ans);
    while(scanf("%s", temp) != EOF){
        int count = 0, len = strlen(ans), rearlen = strlen(temp);
        for(count = rearlen; count>0; count--){
            int check = 1;
            for(int p=0; p<count; p++)
                if(temp[p] != ans[len-count+p]){
                    check = 0;
                    break;
                }
            if(check)break;
        }
        for(int p=0; p<rearlen-count; p++){
            ans[len+p] = temp[count+p];
            if(p == rearlen-count-1)
                ans[len+p+1] = '\0';
        }
    }
    printf("%s", ans);
    return 0;
}