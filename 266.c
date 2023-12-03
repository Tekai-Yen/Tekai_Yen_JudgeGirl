#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

int min(int a, int b){return a<b?a:b;}

int calculate(int aindex, int alength, int bindex, int blength, char a[], char b[]){
    if(aindex == alength) return blength - bindex;
    if(bindex == blength) return alength - aindex; 
    if(a[0] == b[0]) return calculate(aindex+1, alength, bindex+1, blength, a+1, b+1);
    return 1 + min(calculate(aindex+1, alength, bindex, blength, a+1, b), calculate(aindex, alength, bindex+1, blength, a, b+1));
}

int main()
{
    int N = 1, id1 = -1, id2 = -1, current = INT_MAX;
    char data[105][15];//Notice! the array is 1-based instead of 0-based!!
    while(scanf("%s", data[N]) != EOF){N++;}
    N--;
    for(int p=1; p<N; p++){
        for(int q=p+1; q<=N; q++){
            int plen = strlen(data[p]), qlen = strlen(data[q]);
            if(plen - qlen > current || qlen - plen > current) continue;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            int distance = calculate(0, plen, 0, qlen, data[p], data[q]);
            if(distance < current){
                id1 = p;
                id2 = q;
                current = distance;
            }
        }
    }
    printf("%d %d %d", current, id1, id2);
    return 0;
}