#include<stdio.h>
#include<string.h>
#define MAXN 25

int buildup_set(int set, char letter){
    int bit = letter - 'a';
    return set | (1<<bit);
}

int calculate(char temp[]){
    int len = strlen(temp), ans = 0;
    for(int p=0; p<len; p++){
        ans += temp[p] - 'a' + 1;
    }
    return ans;
}

int min(int a, int b){return (a<b)?a:b;}

int solve(int N, char data[MAXN][60], int set, int current, int ans){
    if(current >= N) return 0;
    if(set == (1<<26)-1) return ans;
    int temp = 0, len = strlen(data[current]), value = 0;;
    for(int p=0; p<len; p++)
        temp = buildup_set(temp, data[current][p]);
    value = calculate(data[current]);
    return min(solve(N, data, (set | temp), current+1, ans+value), solve(N, data, set, current+1, ans));
}

int main()
{
    int N = 0;
    while(scanf("%d", &N) != EOF){
        char data[MAXN][60];
        for(int p=0; p<N; p++) scanf("%s", data[p]);
        printf("%d\n", solve(N, data, 0, 0, 0));
    }
    return 0;
}