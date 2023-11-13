#include<stdio.h>
#include<string.h>
#include<math.h>
#define int long long
const char code[10] = {')', '!', '@', '#', '$', '%', '^', '&', '*', '('};

int transdigit(char target){
    for(int p=0; p<10; p++)
        if(target == code[p])
            return p;
}

int transnumber(char *begin, int n){
    int number = 0;
    for(int p=n-1; p>=0; p--)
        number += transdigit(begin[n-1-p]) * pow(10, p); 
    return number;
}

signed main()
{
    char data[1000050], *MSB = &data[0], *LSB = &data[0];
    scanf("%s", data);
    int len = strlen(data), ans = 0, digitnum = 1, current = 0;
    while(*MSB != '\0' && *LSB != '\0'){
        LSB++;
        if(*LSB == '+'){
            current = transnumber(MSB, digitnum);
            ans += current;
            LSB++;
            MSB = LSB;
            digitnum = 1;
        }
        else if(*LSB == '*'){
            current = transnumber(MSB, digitnum);
            LSB++;
            MSB = LSB;
            digitnum = 1;
            while(1){
                LSB++;
                if(*LSB == '*'){
                    current *= transnumber(MSB, digitnum);
                    LSB++;
                    MSB = LSB;
                    digitnum = 1;
                }
                else if(*LSB == '+' || *LSB == '\0'){
                    current *= transnumber(MSB, digitnum);
                    ans += current;
                    if(*LSB == '+'){
                        LSB++;
                        MSB = LSB;
                    }
                    digitnum = 1;
                    break;
                }
                else digitnum++;
            }
            if(*LSB == '\0' || *MSB == '\0') break;
            digitnum = 1;
        }
        else if(*LSB == '\0'){
            ans += transnumber(MSB, digitnum);
            digitnum = 1;
        }
        else
            digitnum++;
    }
    if(digitnum != 1) ans = transnumber(&data[0], len);
    printf("%lld", ans);
    return 0;
}