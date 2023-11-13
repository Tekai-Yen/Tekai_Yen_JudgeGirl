#include<stdio.h>
#include<stdbool.h>

int main()
{
    int s, c, k;
    scanf("%d%d", &s, &c);
    int hash[100000][10] = {0};
    while(scanf("%d", &k) != EOF){
        int index = (77*k + 2222) % s;
        bool found = false;        
        for(int p=0; p<c; p++)
            if(hash[index][p] == k){
                printf("%d %d\n", k, index);
                hash[index][p] = 0;
                found = true;
                break;
            }
        if(!found)
            for(int p=0; p<c; p++)
                if(hash[index][p] == 0){
                    hash[index][p] = k;
                    break;
                }  
    }
    return 0;
}