#include <stdio.h>
#include<stdbool.h>
#include<limits.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

int main() {
    int x;
    long long int data = 0, temp;
    while (ReadInt(&x)) {
        long long int temp = x, copy = data;
        int times = 0;//0-7組
        while(times < 8){
            if((copy & 255) == temp){
                break;
            }
            else{
                copy >>= 8;
                times++;
            }
        }
        //printf("times = %d\n", times);
        if(times == 8){//書架上沒有
            data <<= 8;
            data += temp;
        }
        else{//書架上有
            long long int sheet = 0, cover = -1;
            sheet = (1ll << (times*8)) - 1; 
            sheet &= data;
            sheet <<= 8;
            
            long long int hahaha = 0;
            if(times != 7) hahaha = ~((1ll << (times+1)*8) - 1);
            
            data &= hahaha;
            data += sheet;
            data += temp;
        }
    }    
    // output your answer
    int ans[8];
    for(int p=7; p>=0; p--){
        long long int temp = 255;
        ans[p] = temp & data;
        data >>= 8;
        
    }
    for(int p=0; p<8; p++){
        printf("%d ", ans[p]);
    }
    return 0;
}