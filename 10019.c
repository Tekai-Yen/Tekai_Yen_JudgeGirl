#include<stdio.h>
#include<ctype.h>

int main()
{
    char temp[105];
    while(scanf("%[^\n]", &temp) != EOF){
        getchar();
        char *begin = temp, *ptr = temp;
        while(*ptr != '\0')
            ptr++;
        ptr--;
        while(isspace(*ptr))
            ptr--;
        ptr++;
        *ptr = '\0';
        while(isspace(*begin))
            begin++;
        printf("%s\n", begin);
    }
    return 0;
}