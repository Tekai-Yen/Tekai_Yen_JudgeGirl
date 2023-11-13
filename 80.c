#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int times;
    scanf("%d",&times);
    
    //while(scanf("%d%d%d%d%d%d", x[0], y[0], x[1], y[1], x[2], y[2]) != EOF){

    while(times--){    
        int x[3], y[3], l[3];//l代表邊長的平方

        for(int p=0 ; p<3 ; p++){
            scanf("%d%d", &x[p], &y[p]);
        }

        for(int p=0 ; p<3 ; p++){
            l[p] = pow(x[(p+1)%3]-x[p], 2) + pow(y[(p+1)%3]-y[p], 2);
        }
        if(l[0]==l[1] || l[1]==l[2] || l[2]==l[0]){
            printf("isosceles\n");
            continue;
        }
        
        for(int q=0 ; q<2 ; q++){//bubble sort
            
            for(int p=0 ; p<2-q ; p++){

                if(l[p]<l[p+1]){
                    int a=l[p];
                    l[p]=l[p+1];
                    l[p+1]=a;
                }
            }
            
        }

        if(l[0] > l[1]+l[2]) printf("obtuse\n");
        if(l[0] < l[1]+l[2]) printf("acute\n");
        if(l[0] == l[1]+l[2]) printf("right\n");
        
    }

    return 0;
}