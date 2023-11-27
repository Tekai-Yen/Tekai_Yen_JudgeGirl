#include <stdio.h>
#include <stdlib.h>
 
void solve(long long club[101], long long cur, int index[101], int own, int n, int k, int used[101], int pre){
    if(own == k){
        for(int i = 0;i < own;i++) printf("%d\n", index[i]);
        exit(0);
    }
    for(int i = pre;i < n;i++){
        if(used[i]) continue;
        if((cur & club[i]) != 0) continue;
        used[i] = 1;
        index[own] = i;
        solve(club, (cur | club[i]), index, own + 1, n, k, used, i);
        used[i] = 0;
    }
}

int main() {

    long long club[101];
    int index[101];
    int used[101] = {0};
    int n, k;
    scanf("%d%d", &n, &k);
 
    for(int i = 0;i < n;i++){
        int people;
        club[i] = 0;
        scanf("%d", &people);
        for(int j = 0;j < people;j++){
            int x;
            scanf("%d", &x);
            club[i] += (1ll << x);
        }
    }
 
    solve(club, 0, index, 0, n, k, used, 0);
 
    return 0;
}
