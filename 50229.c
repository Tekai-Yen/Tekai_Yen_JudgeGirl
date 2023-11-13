#include<stdio.h>

int main()
{
    int n, x, y;
    scanf("%d", &n);
    int data[n][2];
    for(int p=0 ; p<n ; p++)
        scanf("%d", &data[p][0]);
    for(int p=0 ; p<n ; p++)
        scanf("%d", &data[p][1]);
    while(scanf("%d%d", &x, &y) != EOF){
        if(x == n) data[y][1] = data[y][0];
        else if(y == n) data[x][1] = 0;
        else{
            int temp = (data[y][0]-data[y][1] < data[x][1]) ? data[y][0]-data[y][1] : data[x][1];
            data[x][1] -= temp;
            data[y][1] += temp;
        }
    }
    for(int p=0 ; p<n ; p++)
        printf("%d ", data[p][1]);
    
    return 0;
}