#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int cal(int data[], int n){
    int ans = 0;
    for(int p=0; p<n; p++){
        ans += data[p]*pow(10, n-p-1);
    }
    return ans;
}

int main()
{
    char temp[10000];
    int count = 0;
    while(scanf("%s", temp) != EOF){
        int data[10000];
        int l = strlen(temp);
        for(int p=0; p<l; p++){
            if(temp[p]>='0' && temp[p]<='9'){
                data[count] = temp[p] - '0';
                count++;
            }
            else{
                if(count == 0)continue;
                printf("%d\n", cal(data, count));
                count = 0;
            }
        }
        if(count)printf("%d\n", cal(data, count));
    }
    return 0;
}