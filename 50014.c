#include <stdio.h>

int subset(int numbers[], int n, int K, int S){
    if(S == 0 && K == 0) return 1; 
    if(K < 0 || n < S || n == 0 || S < 0) return 0;
    return subset(numbers+1, n-1, K-numbers[0], S-1) || subset(numbers+1, n-1, K, S);   
}
 
int main() {
    int n, K, S;
    while (scanf("%d %d %d", &n, &K, &S) == 3) {
        int A[128];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        printf("%d\n", subset(A, n, K, S));
    }
    return 0;
}