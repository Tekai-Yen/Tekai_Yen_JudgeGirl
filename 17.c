#include<stdio.h>

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    int temp[r+1][c];
    for(int p=0 ; p<r ; p++)
        for(int q=0 ; q<c ;q++){
            scanf("%d", &temp[p][q]);
        }
    for(int p=0 ; p<c ; p++){
        int count = 0;
        for(int q=0 ; q<r ; q++){
            count += temp[q][p];
        }
        printf("%d\n", count/r);
    }
    return 0;
}