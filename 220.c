#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char tempy[1000000], temp;
    int count = -100, ans = 0;
    while(gets(tempy)){
        for(int p=0; p<strlen(tempy); p++){
            temp = tempy[p];
            if(temp == '.'){
                count = 0;
                if(p == strlen(tempy)-1){
                    count = -100;
                    ans++;
                }
            }
            else if(temp == ' '){
                count++;
                //printf("FFFFF\n");
            }
            else if(temp == '\n'){
                if(count >= 0){
                    ans++;
                    count = -100;
                }
            }
            else{
                count = -100;
            }
            if(count == 2){
            count = -100;
            ans++;
            }
        }
        
    }
    if(!count)ans++;
    printf("%d", ans);
    return 0;
}