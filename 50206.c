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
    char temp[1000000];
    Data data[100000];
    int datacounter = 0;
    while(scanf("%s", &temp) != EOF){
        //printf("FFF");
        int len = strlen(temp);
        char *ptr;
        if(len < 3) continue;
        for(int p=0; p<len-2; p++){
            ptr = temp + p;
            bool isnew = 1;
            for(int q=0; q<datacounter; q++){
                if(compare(ptr, data[q].str) == 1){
                    data[q].times++;
                    isnew = 0;
                    break;
                }
            }
            if(isnew){
                data[datacounter].str[0] = ptr[0];
                data[datacounter].str[1] = ptr[1];
                data[datacounter].str[2] = ptr[2];
                data[datacounter].str[3] = '\0';
                data[datacounter].times = 1;
                datacounter++;
                break;
            }
        }
    }

    for(int p=datacounter-1; p>0; p--){
        for(int q=0; q<p; q++){
            if(data[q].times < data[q+1].times || (data[q].times == data[q+1].times && strcmp(data[q].str, data[q+1].str) > 0)){
                Data haha = data[q];
                data[q] = data[q+1];
                data[q+1] = haha;
            }
        }
    }

    for(int p=0; p<datacounter; p++){
        //printf("%s %d\n", data[p].str, data[p].times);
    }

    for(int p=0; p<3; p++){
        printf("%s\n", data[p].str);
    }
        

    return 0;
}