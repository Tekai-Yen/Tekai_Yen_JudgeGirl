#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int temp[n];
    for(int p=0 ; p<n ; p++)
        scanf("%d", &temp[p]);
    for(int p=n-1 ; p>=0 ; p--){
        printf("%d", temp[p]);
        if(p != 0)printf(" ");
    }
    return 0;
}