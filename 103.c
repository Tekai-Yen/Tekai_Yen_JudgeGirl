#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double data[n][n], value[n], answer[n];
    for(int p=0 ; p<n ; p++)
        for(int q=0 ; q<n ; q++)
            scanf("%lf", &data[p][q]);
    for(int p=0 ; p<n ; p++)
        scanf("%lf", &value[p]);
    for(int p=n-1 ; p>=0 ; p--){
        for(int q=n-1 ; q>=p ; q--){
            if(q==p){
                answer[p] = value[p] / data[p][q];
            }
            else{
                value[p] -= (data[p][q] * answer[q]);
                continue;
            }
        }
    }

    for(int p=0 ; p<n ; p++){
        printf("%lf\n", answer[p]);
    }
    return 0;
}