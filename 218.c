#include<stdio.h>
#define int long long
int Val(int a){
    return (a==0 || a==1)?1:a*Val(a-1);
}

int Cal(int a, int b){
    return Val(a)/(Val(b)*Val(a-b));
}

signed main()
{
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for(int p=0; p<=m; p++){
        ans += Cal(n, p);
        //printf("C(%lld,%lld) = %d\n",n, p, Cal(n,p));
        //printf("ans = %d\n\n", ans);
    }
    printf("%lld", ans);
    return 1;
}

//會TLE