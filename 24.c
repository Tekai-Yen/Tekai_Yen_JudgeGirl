#include<stdio.h>
#include<string.h>

int main()
{
    char temp[1000];
    scanf("%s", &temp);
    int l = strlen(temp), a=0, b=0, c=0, d=0;
    for(int p=0 ; p<l ; p++){
        if(temp[p]>='0' && temp[p]<='9')
            a++;
        if((temp[p]>='A'&&temp[p]<='Z') || (temp[p]>='a'&&temp[p]<='z'))
            b++;
        if(temp[p]=='a'||temp[p]=='e'||temp[p]=='i'||temp[p]=='o'||temp[p]=='u'||temp[p]=='A'||temp[p]=='E'||temp[p]=='I'||temp[p]=='O'||temp[p]=='U')
            c++;
        d=b-c;  
        
    }
    printf("%d %d %d %d", a, b, c, d);
    return 0;
}