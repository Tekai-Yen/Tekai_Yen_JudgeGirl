#include<stdio.h>

int main()
{
    char temp, data[3][10] = {{'q','w','e','r','t','y','u','i','o','p'}, {'a','s','d','f','g','h','j','k','l',' '}, {'z','x','c','v','b','n','m',' ',' ',' '}};
    int x, y, oper, dx[6] = {0,-1,-1,0,1,1}, dy[6] = {1,1,0,-1,-1,0};
    scanf("%c", &temp);
    for(int p=0; p<3; p++)
        for(int q=0; q<10; q++)
            if(data[p][q] == temp){
                x = p;
                y = q;
            }
    printf("%c\n", temp);
    while(scanf("%d", &oper) != EOF){
        int newx = x + dx[oper], newy = y + dy[oper];
        if(newx<0 || newx>2 || newy<0 || newy>9 || data[newx][newy] == ' '){
            continue;
        }
        x = newx;
        y = newy;
        printf("%c\n", data[x][y]);
    }
    return 0;
}