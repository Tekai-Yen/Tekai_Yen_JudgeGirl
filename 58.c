#include<stdio.h>
#define MAX 400

int DFS(int data[MAX][MAX], int x, int y, int N, int M){
    data[x][y] = 0;
    int temp = 1;
    if(x+1<N && data[x+1][y]==1) temp += DFS(data, x+1, y, N, M);
    if(x-1>=0 && data[x-1][y]==1) temp += DFS(data, x-1, y, N, M);
    if(y+1<M && data[x][y+1]==1) temp += DFS(data, x, y+1, N, M);
    if(y-1>=0 && data[x][y-1]==1) temp += DFS(data, x, y-1, N, M);
    return temp;
}

int main()
{
    int N, M, data[MAX][MAX] = {0}, answersheet[2*MAX*MAX+2], count = 0;
    scanf("%d%d", &N, &M);
    for(int p=0; p<N; p++)
        for(int q=0; q<M; q++)
            scanf("%d", &data[p][q]);
    for(int p=0; p<N; p++)
        for(int q=0; q<M; q++){
            if(data[p][q] == 1){
                answersheet[count] = DFS(data, p, q, N, M);
                count++;
            }
        }
    for(int p=count-1; p>=0; p--)
        for(int q=0; q<p; q++){
            if(answersheet[q] < answersheet[q+1]){
                int temp = answersheet[q];
                answersheet[q] = answersheet[q+1];
                answersheet[q+1] = temp;
            }
        }
    for(int p=0; p<count; p++){printf("%d\n", answersheet[p]);}
    return 0;
}