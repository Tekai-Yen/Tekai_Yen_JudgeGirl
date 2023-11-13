#include<stdio.h>

int main()
{
    int n, m;
    scanf("%d", &n);
    int data[n];
    for(int p=0 ; p<n ; p++)
        scanf("%d", &data[p]);
    scanf("%d", &m);
    int ans[m];
    for(int p=0 ; p<m ; p++)
        ans[p] = 0;
    while(n--){
        ans[data[n]%m]++;
    }
    for(int p=0 ; p<m ;p++)
        printf("%d\n", ans[p]);
    return 0;
}