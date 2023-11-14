#include<stdio.h>

int tekai(int x, int y, int c, int data[12][12]){
    if(y == c-1 && x == 0) return 1;
    int up = 0, right = 0;
    if(x > 0 && data[x-1][y] == 1)
        up = tekai(x-1, y, c, data);
    if(y < c-1 && data[x][y+1] == 1)
        right = tekai(x, y+1, c, data);
    return up + right;
}

int main()
{
    int r, c, data[12][12];
    scanf("%d%d", &r, &c);
    for(int p=0; p<r; p++)
        for(int q=0; q<c; q++)
            scanf("%d", &data[p][q]);
    printf("%d", tekai(r-1, 0, c, data));
    return 0;
}