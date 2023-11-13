#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool compare(char a[], char b[]){
    for(int p=0; p<3; p++)
        if(a[p] != b[p])
            return false;
    return true;
}

typedef struct thedata{
    char str[4];
    int times;
}Data;

int main()
{
    int data[26][26][26];
    for(int p=0; p<26; p++)
        for(int q=0; q<26; q++)
            for(int r=0; r<26; r++)
                data[p][q][r] = 0;
    char temp[1000000];
    while(scanf("%s", &temp) != EOF){
        int len = strlen(temp);
        for(int p=0; p<len-2; p++){
            char *ptr = temp + p;
            data[ptr[0]-'a'][ptr[1]-'b'][ptr[2]-'c']++;
        }
    }
    Data answer[3];
    for(int p=0; p<3; p++)[
        answer[p].times = -1;
    ]
    for(int p=0; p<26; p++)
        for(int q=0; q<26; q++)
            for(int r=0; r<26; r++){
                if(data[p][q][r] == 0) continue;
                for(int t=0; t<3; t++){
                    if(data[p][q][r] > )
                }
            }
}