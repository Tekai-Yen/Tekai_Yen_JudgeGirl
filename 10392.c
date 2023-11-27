#include <stdio.h>
 
void solve(int l, int x, int y, int centerx, int centery, int two[2][2]){
    if(l == 1) return;
    if(l == 2){
        printf("%d %d %d\n", two[x-centerx+1][y-centery+1], centerx, centery);
        return;
    }
    if(0 <= x-centerx && x-centerx < (l/2)){//洞在右側
        if(0 <= y-centery && y-centery < (l/2)){//右上
            printf("1 %d %d\n", centerx, centery);
            solve(l/2, x, y, centerx+l/4, centery+l/4, two);
            solve(l/2, centerx-1, centery, centerx-l/4, centery+l/4, two);
            solve(l/2, centerx, centery-1, centerx+l/4, centery-l/4, two);
            solve(l/2, centerx-1, centery-1, centerx-l/4, centery-l/4, two);
        }
        else{//右下
            printf("3 %d %d\n", centerx, centery);
            solve(l/2, x, y, centerx+l/4, centery-l/4, two);
            solve(l/2, centerx, centery, centerx+l/4, centery+l/4, two);
            solve(l/2, centerx-1, centery, centerx-l/4, centery+l/4, two);
            solve(l/2, centerx-1, centery-1, centerx-l/4, centery-l/4, two);
        }
    }
    else{
        if(0 <= y-centery && y-centery < (l/2)){//左上
            printf("2 %d %d\n", centerx, centery);
            solve(l/2, x, y, centerx-l/4, centery+l/4, two);
            solve(l/2, centerx, centery, centerx+l/4, centery+l/4, two);
            solve(l/2, centerx-1, centery-1, centerx-l/4, centery-l/4, two);
            solve(l/2, centerx, centery-1, centerx+l/4, centery-l/4, two);
 
        }
        else{//左下
            printf("4 %d %d\n", centerx, centery);
            solve(l/2, x, y, centerx-l/4, centery-l/4, two);
            solve(l/2, centerx, centery, centerx+l/4, centery+l/4, two);
            solve(l/2, centerx-1, centery, centerx-l/4, centery+l/4, two);
            solve(l/2, centerx, centery-1, centerx+l/4, centery-l/4, two);
        }
    }
}
 
int main(){
    int l, x, y, two[2][2];
    two[0][0] = 4;
    two[0][1] = 2;
    two[1][0] = 3;
    two[1][1] = 1;
    scanf("%d%d%d", &l, &x, &y);
    solve(l, x, y, l/2, l/2, two);
    return 0;
}