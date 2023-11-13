#include<stdio.h>

void execute(int temp[][500], int x, int y, int r, int c)
{
    if(x+1 < r && temp[x][y] == temp[x+1][y]){//下
        if(y-1 >= 0 && temp[x+1][y] == temp[x+1][y-1]){
            temp[x][y] = temp[x+1][y] = temp[x+1][y-1] = 0;
            return;
        }
        if(y+1 < c && temp[x+1][y] == temp[x+1][y+1]){
            temp[x][y] = temp[x+1][y] = temp[x+1][y+1] = 0;
            return;
        }
    }
    if(x-1 >= 0 && temp[x][y] == temp[x-1][y]){//上
        if(y-1 >= 0 && temp[x-1][y] == temp[x-1][y-1]){
            temp[x][y] = temp[x-1][y] = temp[x-1][y-1] = 0;
            return;
        }
        if(y+1 < c && temp[x-1][y] == temp[x-1][y+1]){
            temp[x][y] = temp[x-1][y] = temp[x-1][y+1] = 0;
            return;
        }
    }

    if(y+1 < c && temp[x][y] == temp[x][y+1]){//右
        if(x-1 >= 0 && temp[x][y+1] == temp[x-1][y+1]){
            temp[x][y] = temp[x][y+1] = temp[x-1][y+1] = 0;
            return;
        }
        if(x+1 < r && temp[x][y+1] == temp[x+1][y+1]){
            temp[x][y] = temp[x][y+1] = temp[x+1][y+1] = 0;
            return;
        }
    }

    if(y-1 >= 0 && temp[x][y] == temp[x][y-1]){//左
        if(x-1 >= 0 && temp[x][y-1] == temp[x-1][y-1]){
            temp[x][y] = temp[x][y-1] = temp[x-1][y-1] = 0;
            return;
        }
        if(x+1 < r && temp[x][y-1] == temp[x+1][y-1]){
            temp[x][y] = temp[x][y-1] = temp[x+1][y-1] = 0;
            return;
        }
    }
}

int main()
{
    int r, c, temp[500][500];
    scanf("%d%d", &r, &c);
    for(int p=0 ; p<r ; p++)
        for(int q=0 ; q<c ; q++)
            scanf("%d", &temp[p][q]);
    for(int p=0 ; p<r ; p++){//往右走
        for(int q=0 ; q<c-2 ; q++){
            if(temp[p][q] == temp[p][q+1] && temp[p][q+1] == temp[p][q+2])
                temp[p][q] = temp[p][q+1] = temp[p][q+2] = 0;
        }
    }
    for(int p=0 ; p<r-2 ; p++){//往下走
        for(int q=0 ; q<c ; q++){
            if(temp[p][q] == temp[p+1][q] && temp[p+1][q] == temp[p+2][q])
                temp[p][q] = temp[p+1][q] = temp[p+2][q] = 0;
        }
    }
    int vertical[2][2] = {{1,0} , {-1,0}}, horizontal[2][2] = {{0,1} , {0,-1}};
    for(int p=0 ; p<r ; p++){//L形直角8方向搜索
        for(int q=0 ; q<c ; q++){
            if(temp[p][q])execute(temp, p, q, r, c);
        }
    }
    //printf("\n");
    for(int p=0 ; p<r ; p++){
        for(int q=0 ; q<c ; q++){
            printf("%d", temp[p][q]);
            if(q != c-1)printf(" ");
        }
        printf("\n");
    }
    
    
    return 0;
}