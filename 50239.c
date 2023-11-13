#include<stdio.h>
#include<string.h>

int main()
{
    int N, M, position;
    scanf("%d%d", &N, &M);
    char A[N], temp[50];
    for(int p=0; p<N; p++){
        A[p] = '\0';
    }
    while(scanf("%s%d", temp, &position) != EOF){
        //printf("%s %d\n", temp, position);
        int len = strlen(temp);
        char *ptr = A + position;
        for(int p=0; p<len; p++){
            if(ptr[p] == '\0'){
                ptr[p] = temp[p];
            }
            else{
                ptr[p] = (ptr[p] + temp[p])/2;
            }
        }
    }
    for(int p=0; p<N-1; p++){
        if(A[p] == '\0')
            A[p] = ' ';
    }
    printf("%s", A);
}