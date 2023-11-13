#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}employee;

typedef struct{
    int id;
    int *haha;
}haha;

int find_people(char a[], char b[], employee data[]){
    for(int p=0; p<32; p++){
        if(strcmp(a, data[p].first_name) == 0 && strcmp(b, data[p].last_name) == 0){
            return p;
        }
    }
}

int id2index(employee data[], int ID){
    for(int p=0; p<32; p++){
        if(data[p].id == ID){
            return p;
        }
    }
}

int main()
{
    employee data[32];
    int N, M;
    scanf("%d", &N);
    for(int p=0; p<N; p++){
        scanf("%d%s%s%d", &data[p].id, data[p].first_name, data[p].last_name, &data[p].boss_id);
    }
    scanf("%d", &M);
    while(M--){
        char a[100], b[100];
        int index1, index2, index1boss = -1, index2boss = -1;
        scanf("%s%s", a, b);
        index1 = find_people(a, b, data);
        scanf("%s%s", a, b);
        index2 = find_people(a, b, data);
        int current = index1;
        bool find_supervisor = 0;
        while(data[current].id != data[current].boss_id){
            int temp = id2index(data, data[current].boss_id);
            if(temp == index2){
                find_supervisor = 1;
                printf("subordinate\n");
                break;
            }
            current = temp;
        }
        if(find_supervisor) continue;
        else{
            index1boss = current;
        }
        current = index2;
        find_supervisor = 0;
        while(data[current].id != data[current].boss_id){
            int temp = id2index(data, data[current].boss_id);
            if(temp == index1){
                find_supervisor = 1;
                printf("supervisor\n");
                break;
            }
            current = temp;
        }
        if(find_supervisor) continue;
        else{
            index2boss = current;
        }
        if(index1boss == index2boss){
            printf("colleague\n");
        }
        else{
            printf("unrelated\n");
        }
    }
    return 0;
}