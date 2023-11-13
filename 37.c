#include<stdio.h>
#include<math.h>

int value(int type, int width, int height, int length)
{
    int worth, a=width, b=height, c=length; 
    switch(type){
        case 79: worth = 30; break;
        case 47: worth = 10; break;
        case 29: worth = 4; break;
        case 82: worth = 5; break;
        case 26: worth = 3; break;
        case 22: worth = 9; break;
        default: return -1;
    }
    if(a<=0 || b<=0 ||c <=0) return -2;
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    if(a < c){
        int temp = c;
        c = a;
        a = temp;
    }
    while(c != 0){
        int temp = c;
        c = a % c;
        a = temp;
    }
    return worth * (width / a) * (height / a) * (length / a) * pow(a, 6);
}