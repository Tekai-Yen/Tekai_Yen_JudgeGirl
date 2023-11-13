#include<stdio.h>

int num(int temp[][100], int n, int x, int y)
{
    int count = 0;
    if(x+1 < n && temp[x+1][y])count++;
    if(y+1 < n && temp[x][y+1])count++;
    if(x-1 >= 0 && temp[x-1][y])count++;
    if(y-1 >= 0 && temp[x][y-1])count++;
    return count;
}

_Bool isturn(int temp[][100], int n, int x, int y)
{
    if(x+1 < n && x-1 >= 0 && temp[x+1][y] == temp[x-1][y])return 0;
    if(y+1 < n && y-1 >= 0 && temp[x][y+1] == temp[x][y-1])return 0;
    return 1;
}

int main()
{
    int n;  scanf("%d", &n);
    int map[100][100];
    for(int p=0 ; p<n ; p++)
        for(int q=0 ; q<n ; q++)
            scanf("%d", &map[p][q]);

    int inter = 0, T = 0, turn = 0, dead = 0;

    //printf("\n");

    for(int p=0 ; p<n ; p++){
        for(int q=0 ; q<n ; q++){
            if(!map[p][q])continue;
            //printf("%d ", num(map, n, p, q));
            switch(num(map, n, p, q)){
                case 0:
                    break;
                case 1:
                    dead++;
                    break;
                case 2:
                    if(isturn(map, n, p, q))
                        turn++;
                    break;
                case 3:
                    T++;
                    break;
                case 4:
                    inter++;
                    break;
            }
        }
        //printf("\n");
    }
        
    printf("%d\n%d\n%d\n%d\n", inter, T, turn, dead);
    return 0;
}