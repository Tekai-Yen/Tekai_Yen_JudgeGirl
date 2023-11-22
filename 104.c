#include<stdio.h>

int tekai(int d[], int e[], int f[],int a,int b,int c){
    if(a<0 || b<0 || c<0) return 0;
    if(a==0 && b==0 && c==0) return 1;
    return tekai(d, e, f, a-d[0], b-d[1], c-d[2]) + tekai(d, e, f, a-e[0], b-e[1], c-e[2]) + tekai(d, e, f, a-f[0], b-f[1], c-f[2]);
}

void loop(int N, int D[], int E[], int F[]){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(tekai(D, E, F, a, b, c) != 0) printf("yes\n");
    else printf("no\n");
    if(N>1) loop(N-1,D, E, F);
    else return;
}

int main()
{
    int D[3], E[3], F[3], N;
    scanf("%d%d%d%d%d%d%d%d%d%d", &D[0], &D[1], &D[2], &E[0], &E[1], &E[2], &F[0], &F[1], &F[2], &N);
    loop(N, D, E, F);
    return 0;
}