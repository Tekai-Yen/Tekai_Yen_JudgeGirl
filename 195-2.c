#include<stdio.h>

int deter(int map[][3])
{
    for(int p=0 ; p<3 ; p++){
        _Bool B = 1, W = 1;
        for(int q=0 ; q<3 ; q++){
            if(map[p][q] == 0){
                B = 0;
                W = 0;
            }
            else if(map[p][q] == 1){
                W = 0;
            }
            else if(map[p][q] == 2){
                B = 0;
            }
        }
        if(B) return 1;
        if(W) return 2;
    }

    for(int p=0 ; p<3 ; p++){
        _Bool B = 1, W = 1;
        for(int q=0 ; q<3 ; q++){
            if(map[q][p] == 0){
                B = 0;
                W = 0;
            }
            else if(map[q][p] == 1)
                W = 0;
            else if(map[q][p] == 2)
                B = 0;
        }
        if(B) return 1;
        if(W) return 2;
    }

    if(map[0][0] == map[1][1] && map[1][1] == map[2][2]){
        if(map[1][1] == 1) return 1;
        if(map[1][1] == 2) return 2;
    }
    if(map[0][2] == map[1][1] && map[1][1] == map[2][0]){
        if(map[1][1] == 1) return 1;
        if(map[1][1] == 2) return 2;
    }
    return 0;
}

void print(int map[][3]){
    printf("\n\n");
    for(int p=0 ; p<3 ; p++){
        for(int q=0 ; q<3 ; q++){
            printf("%d ", map[p][q]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    int map[3][3] = {0}, n;
    _Bool black = 1;
    scanf("%d", &n);
    while(n--){
        int x, y;
        scanf("%d%d", &x, &y);
        if(map[x][y] != 0 || x<0 || x>2 || y<0 || y>2){
            //black = !black;
            continue;
        }
        if(black)
            map[x][y] = 1;
        else
            map[x][y] = 2;
        black = !black;
    }

    //print(map);

    switch(deter(map)){
        case 0:
            printf("There is a draw.");
            break;
        case 1:
            printf("Black wins.");
            break;
        case 2:
            printf("White wins.");
    }
    return 0;
}