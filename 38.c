#include<stdio.h>
#include<stdbool.h>

bool tekai(int A, int B, int C, int D, int a, int b, int c){
    if(D == 0) return true;
    if(D < 0) return false;
    bool solution = false;
    if(a > 0) solution = solution || tekai(A, B, C, D-A, a-1, b, c);
    if(b > 0) solution = solution || tekai(A, B, C, D-B, a, b-1, c);
    if(c > 0) solution = solution || tekai(A, B, C, D-C, a, b, c-1);
    return solution;
}

int main(){
    int N, A, B, C, D, a, b, c;
    scanf("%d", &N);
    while(N--){
        scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
        if(tekai(A, B, C, D, a, b, c)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}