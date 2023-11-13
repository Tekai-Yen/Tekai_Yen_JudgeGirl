#include<stdio.h>
#include<string.h>
#define MAX 100

int find_name(char Name[MAX][100], char target[], int N){
    for(int p=0; p<N; p++)
        if(strcmp(Name[p], target) == 0)
            return p;
}

int main()
{
    int N, M;
    scanf("%d", &N);
    char data[N][15][65], name[MAX][100];
    int number[N];
    for(int p=0; p<N; p++){
        scanf("%s", name[p]);
        scanf("%d", &number[p]);
        for(int q=0; q<number[p]; q++)
            scanf("%s", data[p][q]);
    }
    scanf("%d", &M);
    while(M--){
        char temp1[65], temp2[65], answer[100][100];
        scanf("%s%s", temp1, temp2);
        int count = 0, index1 = find_name(name, temp1, N), index2 = find_name(name, temp2, N);
        for(int p=0; p<number[index1]; p++)
            for(int q=0; q<number[index2]; q++)
                if(strcmp(data[index1][p], data[index2][q]) == 0){
                    strcpy(answer[count], data[index1][p]);
                    count++;
                }
        for(int p=count-2; p>=0; p--)
            for(int q=0; q<=p; q++)
                if(strcmp(answer[q], answer[q+1]) > 0){
                    char temp[150];
                    strcpy(temp, answer[q]);
                    strcpy(answer[q], answer[q+1]);
                    strcpy(answer[q+1], temp);
                }
        for(int p=0; p<count; p++){
            printf("%s", answer[p]);
            if(p == count-1) printf("\n");
            else printf(" ");
        }
        if(!count) printf("nothing\n");
    }
    return 0;
}