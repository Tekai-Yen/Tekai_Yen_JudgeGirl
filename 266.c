#include<stdio.h>
#include<string.h>

void cuthead(char* prison){
    int len = strlen(prison);
    for(int p=0; p<len-1; p++){
        prison[p] = prison[p+1];
    }
    prison[len-1] = '\0';
}

int calculate(char a[], char b[]){
    int alen = strlen(a), blen = strlen(b);
    if(a == 0) return blen;
    if(b == 0) return alen;
}

int main()
{
    int N = 1;
    char data[105][15];//Notice! the array is 1-based instead of 0-based!!
    while(scanf("%s", data[N]) != EOF){N++;}
    N--;



    return 0;   
}