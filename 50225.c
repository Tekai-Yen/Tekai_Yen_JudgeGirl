#include<stdio.h>

int main()
{
    int n, m, k, count = 0;
    scanf("%d%d%d", &n, &m, &k);
    _Bool going_right = 1, nextdown = 1;
    int x = 0, y = 0;
    while(1){
        //printf("AAA\n");
        if(going_right){
            for(int p=y ; p<m ; p++){
                count++;
                if(count == k){
                    printf("%d %d", x+1, p+1);
                    return 0;
                }
            }
        }
        else{
            for(int p=x ; p<n ; p++){
                count++;
                if(count == k){
                    printf("%d %d", p+1, y+1);
                    return 0;
                }
            }
        }

        going_right = !going_right;
        //printf("%d", going_right);
        if(nextdown)x++;
        else y++;
        nextdown = !nextdown;

    }
}