#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
    char lastname[85], firstname[85], ID[85];
    int salary, age;
}Data;

bool string_compare(char a[85], char b[85]){
    int len = strlen(a);
    for(int p=0; p<len; p++)
        if(a[p] != b[p])
            return true;
    return false;//完全相同輸出0
}

int char2int(char temp[85]){
    int len = strlen(temp), ans = 0, tekai = 1;
    for(int p=len-1; p>=0; p--){
        ans += (int)(temp[p]-'0') * tekai;
        tekai *= 10;
    }
    return ans;
}

void print(Data temp, int count, int oper[5]){
    for(int p=0; p<count; p++){
        if(p != 0) printf(" ");
        if(oper[p] == 1){
            printf("%s", temp.lastname);
        }
        else if(oper[p] == 2){
            printf("%s", temp.firstname);
        }
        else if(oper[p] == 3){
            printf("%s", temp.ID);
        }
        else if(oper[p] == 4){
            printf("%d", temp.salary);
        }
        else{
            printf("%d", temp.age);
        }

        /*
        switch(oper[p]){
            case 1:
                printf("%s", temp.lastname);
                break;
            case 2:
                printf("%s", temp.firstname);
                break;
            case 3:
                printf("%s", temp.ID);
                break;
            case 4:
                printf("%d", temp.salary);
                break;
            case 5:
                printf("%d", temp.age);
                break;
        }*/
        if(p == count-1) printf("\n");
    }
}

bool checknumber(Data lala, int target, char oper[5], int haha){//0-salary  1-age
    int temp = (target == 0)? lala.salary : lala.age;
    if(oper[0] == oper[1] && oper[0] == '=')
        return temp == haha;
    else if(oper[0] == '>' && oper[1] == '=')
        return temp >= haha;
    else if(oper[0] == '<' && oper[1] == '=')
        return temp <= haha;
    else if(oper[0] == '!' && oper[1] == '=')
        return temp != haha;
    else if(oper[0] == '>')
        return temp > haha;
    else if(oper[0] == '<')
        return temp < haha;
}

bool checkchar(Data lala, char target[85], char oper[5], char a[85]){
    char temp[85];
    if(target[0] == 'l')
        strcpy(temp, lala.lastname);
    else if(target[0] == 'f')
        strcpy(temp, lala.firstname);
    else if(target[0] == 'I')
        strcpy(temp, lala.ID);
    if(oper[0] == '=')
        return !string_compare(temp, a);
    else if(oper[0] == '!')
        return string_compare(temp, a);
}

int main()
{
    int N, M;
    scanf("%d", &N);
    Data data[N];
    for(int p=0; p<N; p++){
        scanf("%s%s%s%d%d", data[p].lastname, data[p].firstname, data[p].ID, &data[p].salary, &data[p].age);
        //printf("%s %s %s %d %d\n\n", data[p].lastname, data[p].firstname, data[p].ID, data[p].salary, data[p].age);
    }
    scanf("%d", &M);
    while(M--){
        int operation[8], count = 0;
        char temp[100], condition[80], sign[5], haha[85];
        while(scanf("%s", temp) && !(temp[0] == 'w' && temp[1] == 'h')){
            if(temp[0] == 'l'){
                operation[count] = 1;
                count++;
                continue;
            }
            if(temp[0] == 'f'){
                operation[count] = 2;
                count++;
                continue;
            }
            if(temp[0] == 'I'){
                operation[count] = 3;
                count++;
                continue;
            }
            if(temp[0] == 's' && temp[1] == 'a'){
                operation[count] = 4;
                count++;
                continue;
            }
            if(temp[0] == 'a'){
                operation[count] = 5;
                count++;
                continue;
            }
        }
        scanf("%s%s%s", condition, sign, haha);
        if(condition[0] == 'a' || condition[0] == 's'){
            int fuck = (condition[0] == 'a')? 1 : 0, number = char2int(haha);
            for(int p=0; p<N; p++){
                if(checknumber(data[p], fuck, sign, number)){
                    print(data[p], count, operation);
                }
            }
        }
        else{
            for(int p=0; p<N; p++){
                if(checkchar(data[p], condition, sign, haha)){
                    print(data[p], count, operation);
                }
            }
        }
    }
    return 0;
}