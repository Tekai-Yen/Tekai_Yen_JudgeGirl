#include<stdio.h>

int main()
{
    char temp[105], ptr = 0;
    int ans[26] = {0};
    scanf("%s", &temp);
    while(temp[ptr] != '\0'){
        if(temp[ptr] >= 'a' && temp[ptr] <= 'z')
            ans[temp[ptr] - 'a']++;
        if(temp[ptr] >= 'A' && temp[ptr] <= 'Z')
            ans[temp[ptr] - 'A']++;
        ptr++;
    }
    for(int p=0; p<26; p++)
        printf("%d\n", ans[p]);
    return 0;
}