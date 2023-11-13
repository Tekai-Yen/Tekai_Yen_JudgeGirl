#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stddef.h>

void mergeString(char** P, char L[26], char* A){
    int trans[150], n = 0, count = 0;
    for(int p=0; p<26; p++)
        trans[(int)L[p]] = p;
    while((P+n) != NULL) n++;
    char *ptr[n];
    for(int p=0; p<n; p++)
        ptr[p] = P[p];
    while(1){
        int decide = -1;
        for(int p=0; p<n; p++){
            if(*ptr[p] == '\0') continue;
            if(decide == -1) decide = p;
            else if(trans[(int)*ptr[p]] < trans[(int)*ptr[decide]])
                decide = p;
        }
        A[count] = *ptr[decide];
        count++;
        ptr[decide]++;
        int allgone = 1;
        for(int p=0; p<n; p++){
            if(*ptr[p] != '\0')
                allgone = 0;
        }
        if(allgone)
            break;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char* P[n + 1];
    char* freeP[n];
    int lengthA = 0;
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d", &m);
        P[i] = (char*)malloc((m + 1) * sizeof(char));
        scanf("%s", P[i]);
        // We may change the pointers in P in mergeString,
        // so we make a copy of P to free them in the last step.
        freeP[i] = P[i];
        lengthA += m;
    }
    P[n] = NULL;
 
    char L[26], buffer[30];
    scanf("%s", buffer);
    strncpy(L, buffer, 26);
 
    char* A = (char *)malloc((lengthA + 1) * sizeof(char));
    mergeString(P, L, A);
    A[lengthA] = '\0';
    printf("%s\n", A);
 
    // free the memory
    for(int i = 0; i < n; i++){
        free(freeP[i]);
    }
    free(A);
}
