#include<stdio.h>

typedef struct ha{
    int no;
    int number;
    int list[20];
    int color;
}Data;

int main()
{
    int N, C, M;
    scanf("%d%d%d", &N, &C, &M);
    Data data[N];
    for(int p=0; p<N; p++){
        data[p].no = p;
        data[p].number = 0;
        data[p].color = -1;
    }    
    for(int p=0; p<M; p++){
        int a, b;
        scanf("%d%d", &a, &b);
        data[a].list[data[a].number] = b;
        data[a].number++;
        data[b].list[data[b].number] = a;
        data[b].number++;
    }
    
    for(int p=0; p<N; p++){
        int col[8] = {0}, hassolution = 0;
        for(int q=0; q<data[p].number; q++){
            if(data[data[p].list[q]].color == -1) continue;
            col[data[data[p].list[q]].color] = 1;
        }
        for(int q=0; q<C; q++){
            if(col[q] == 0){
                data[p].color = q;
                hassolution = 1;
                break;
            }
        }
        if(!hassolution){
            printf("no solution.\n");
            return 0;
        }
    }
    for(int p=0; p<N; p++){
        printf("%d\n", data[p].color);
    }
    return 0;
}