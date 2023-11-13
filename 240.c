#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int times = 0, x[4] = {0}, y[4] = {0}, vector[4][2] = {0}, line[4][2] = {0};

void swap_point(int a, int b){
    int tempx = x[a], tempy = y[a];
    x[a] = x[b];
    y[a] = y[b];
    x[b] = tempx;
    y[b] = tempy;
}

void swap_vector(int a, int b){
    int tempx = vector[a][0], tempy = vector[a][1];
    vector[a][0] = vector[b][0];
    vector[a][1] = vector[b][1];
    vector[b][0] = tempx;
    vector[b][1] = tempy;
}

void printit()
{
    for(int p=0 ; p<4 ; p++)
        printf("%d  %d\n", x[p], y[p]);
}

void print_line()
{
    for(int p=0 ; p<4 ; p++){
        printf("%d %d\n",line[p][0], line[p][1]);
    }
}

int main()
{
    
    scanf("%d", &times);
    while(times--){
        for(int p=0 ; p<4 ; p++)
            scanf("%d%d", &x[p], &y[p]);

        int lowest = 0;
        for(int p=0 ; p<4 ; p++){//找出最左方的點當作原點
            if(x[p] < x[lowest])
                lowest = p;
        }

        swap_point(0, lowest);
        
        for(int p=0 ; p<4 ; p++){//求出其他點對基準點的向量
            vector[p][0] = x[p] - x[0];
            vector[p][1] = y[p] - y[0];
        }
        
        for(int p=1 ; p<=3 ; p++){
            for(int q=p+1 ; q<=3 ; q++){
                if((vector[p][0]*vector[q][1] - vector[p][1]*vector[q][0]) < 0){
                    swap_point(p, q);
                    swap_vector(p, q);
                }
            }
        }

        
        
        for(int p=0 ; p<4 ; p++){//建立順時針向量
            line[p][0] = x[(p+1)%4] - x[p];
            line[p][1] = y[(p+1)%4] - y[p];
        }

        _Bool all_right_angle = 1, all_length_equal = 1;

        for(int p=0 ; p<4 ; p++){
            if(line[p][0]*line[(p+1)%4][0] + line[p][1]*line[(p+1)%4][1] != 0){
                all_right_angle = 0;
                break;
            }
        }

        for(int p=0 ; p<4 ; p++){
            if(pow(line[p][0], 2) + pow(line[p][1], 2) != pow(line[(p+1)%4][0], 2) + pow(line[(p+1)%4][1], 2)){
                all_length_equal = 0;
                break;
            }
        }


        //printit();
        //printf("\n\n");
        //print_line();
        //printf("\n\n");


        if(all_right_angle){
            if(all_length_equal){
                printf("square\n");
                continue;
            }
            else{
                printf("rectangle\n");
                continue;
            }
        }
        else{
            if(all_length_equal){
                printf("diamond\n");
                continue;
            }
            else{
                printf("other\n");
                continue;
            }
        }
    }
    return 0;
}