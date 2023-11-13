#include<stdio.h>

int calculate(int a[][512],int b[][128], int n, int x, int y){
    int temp = 0;
    for(int p=0; p<n; p++)
        for(int q=0; q<n; q++)
            temp += a[x+p][y+q] * b[p][q];
    return temp;
}

int main()
{
    int pic[512][512] = {0}, filter[128][128] = {0}, n, k;
    scanf("%d%d", &n, &k);
    int outcome[n-k+1][n-k+1];
    for(int p=0; p<n; p++)
        for(int q=0; q<n; q++)
            scanf("%d", &pic[p][q]);
    for(int p=0; p<k; p++)
        for(int q=0; q<k; q++)
            scanf("%d", &filter[p][q]);
    for(int p=0; p<n-k+1; p++)
        for(int q=0; q<n-k+1; q++)
            outcome[p][q] = calculate(pic, filter, k, p, q);
    for(int p=0; p<n-k+1; p++){
        for(int q=0; q<n-k+1; q++){
            printf("%d", outcome[p][q]);
            if(q != n-k)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}