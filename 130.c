#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        char a[100], b[100];
        scanf("%s%s", a, b);
        if(strcmp(a, b) == 0){
            printf("%s\n", "yes");
            continue;
        }
        if(strlen(a) == strlen(b)){
            int l = strlen(a), haha = 0;
            for(int p=0; p<l-1; p++){
                char swap = a[p];
                a[p] = a[p+1];
                a[p+1] = swap;
                if(strcmp(a, b) == 0)
                    haha = 1;
                swap = a[p];
                a[p] = a[p+1];
                a[p+1] = swap;
                if(haha)break;
            }
            if(haha){
                printf("%s\n", "yes");
                continue;
            }
        }
        if(strlen(a) - strlen(b) == 1){
            int l = strlen(a), correct = 1;
            for(int p=0; p<l; p++){
                correct = 1;
                for(int q=0; q<l-1; q++){
                    if(q >= p){
                        if(a[q+1] != b[q])
                            correct = 0;
                    }
                    else{
                        if(a[q] != b[q])
                            correct = 0;
                    }
                }
                if(correct){
                    printf("%s\n", "yes");
                    break;
                }
            }
            if(correct)continue;
            
        }
        if(strlen(b) - strlen(a) == 1){
            int l = strlen(b), correct = 1;
            for(int p=0; p<l; p++){
                correct = 1;
                for(int q=0; q<l-1; q++){
                    if(q >= p){
                        if(b[q+1] != a[q])
                            correct = 0;
                    }
                    else{
                        if(b[q] != a[q])
                            correct = 0;
                    }
                }
                if(correct){
                    printf("%s\n", "yes");
                    break;
                }
            }
            if(correct)continue;
        }
        printf("%s\n", "no");
    }
    return 0;
}