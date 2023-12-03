#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void operation(int oper, int data[15][15], int x, int y){//0-addition  1-subtract
    for(int p=-1; p<=1; p++)
        for(int q=-1; q<=1; q++){
            if(oper == 0) data[x+p][y+q]++;
            if(oper == 1) data[x+p][y+q]--;
        }
}

bool legal(int data[15][15], int x, int y){
    for(int p=-1; p<=1; p++)
        for(int q=-1; q<=1; q++)
            if(data[x+p][y+q] < 0)
                return false;
    return true;
}

void print(int answer[15][15]){
    for(int p=1; p<=9; p++){
        for(int q=1; q<=9; q++){
            printf("%d", answer[p][q]);
            if(q != 9)printf(" ");
        }
        printf("\n");
    }
}

bool allzero(int data[15][15]){
    for(int p=1; p<=9; p++)
        for(int q=1; q<=9; q++)
            if(data[p][q] != 0)
                return false;
    return true;
}

void solution(int data[15][15], int answer[15][15], int index){
    if(allzero(data)){
        print(answer);
        exit(0);
    }
    int x = (index-1)/9+1, y = (index-1)%9+1;
    if(x<8)//剪枝超級重要!!!!!沒有剪枝連結果都跑不出來
        for(int p=1; p<=9; p++)
            if(data[x+2][p] > 0) return;
    answer[x][y] = 1;
    operation(1, data, x, y);
    if(legal(data, x, y)){
        solution(data, answer, index-1);
    }
    answer[x][y] = 0;
    operation(0, data, x, y);
    solution(data, answer, index-1);
}

int main()
{
    int data[15][15], answer[15][15];
    for(int p=0; p<15; p++)for(int q=0; q<15; q++){data[p][q] = 100000; answer[p][q] = 0;}
    for(int p=1; p<=9; p++)for(int q=1; q<=9; q++)scanf("%d", &data[p][q]);
    solution(data, answer, 81);
    printf("no solution\n");
    return 0;
}