#include<stdio.h>

void bishop(int data[500][500], int height, int width, int X, int Y)
{
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, 1, -1};

    for(int p=0 ; p<4 ; p++){
        int x = X + dx[p], y = Y + dy[p];
        while(x >= 0 && x <= height && y >= 0 && y<= width && data[x][y] != 0){//The point doesn't out of range and it's not a stone
            data[x][y] = 0;
            x += dx[p];
            y += dy[p];
        }
    }
    data[X][Y] = 0;
}

void rook(int data[500][500], int height, int width, int X, int Y)
{
    int dx[4] = {1,-1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for(int p=0 ; p<4 ; p++){
        int x = X + dx[p], y = Y + dy[p];
        while(x >= 0 && x <= height && y >= 0 && y<= width && data[x][y] != 0){//The point doesn't out of range and it's not a stone
            data[x][y] = 0;
            x += dx[p];
            y += dy[p];
        }
    }
    data[X][Y] = 0;
}

void queen(int data[500][500], int height, int width, int X, int Y){
    bishop(data, height, width, X, Y);
    rook(data, height, width, X, Y);
}

void print(int r, int c, int data[500][500]){
    for(int p=0 ; p<r ; p++){
        for(int q=0 ; q<c ; q++){
            printf("%d", data[p][q]<0?0:1);
            if(q != c-1)printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int h, w, type, c, r;
    scanf("%d%d", &h, &w);
    int data[500][500];
    for(int p=0 ; p<h ; p++)
        for(int q=0 ; q<w ; q++)
            data[p][q] = -1;
    while(scanf("%d%d%d",&type, &c, &r) != EOF){
        switch(type){
            case 0:
                data[r][c] = 0;
                break;
            case 1:
                data[r][c] = 1;
                queen(data, h, w, r, c);
                break;
            case 2:
                data[r][c] = 2;
                bishop(data, h, w, r, c);
                break;
            case 3:
                data[r][c] = 3;
                rook(data, h, w, r, c);
                break;
        }
    }
    print(h, w, data);
    return 0;
}