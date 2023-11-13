#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define TRANS ('A'-'a')

bool garbage(char data[]){
    //if(data[strlen(data)-1] == '.') data[strlen(data)-1] = '\0';
    if(data[0]=='o' && data[1]=='f' && strlen(data) <= 2+1) return 1;
    if(data[0]=='t' && data[1]=='h' && data[2]=='e' && strlen(data)<=3+1) return 1;
    if(data[0]=='a' && data[1]=='n' && data[2]=='d' && strlen(data)<=3+1) return 1;
    if(data[0]=='a' && data[1]=='t' && strlen(data) <= 2+1) return 1;
    return 0;
}

int main()
{
    char temp[1000];
    while(scanf("%s", temp) != EOF){
        if(!garbage(temp))
            printf("%c", temp[0] + TRANS);
        if(temp[strlen(temp)-1] == '.') printf("\n");
    }
    return 0;
}
