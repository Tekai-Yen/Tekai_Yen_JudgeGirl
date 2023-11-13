#include <stdio.h>

int max(int *iptr[], int n){
    int ans = -9999;
    for(int p=0 ; p<n ; p++){
        if(*iptr[p] > ans)
            ans = *iptr[p];
    }
    return ans;
}
 
int main() {
    int n, i;
    int array[100];
    int *iptr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[(i + 3) % n]));
        iptr[i] = &(array[(i + 3) % n]);
    }
    printf("%d\n", max(iptr, n));
    return 0;
}