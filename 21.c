#include "max.h"
int max(int array[5][5]){
    int current = -100000000;
    for(int p=0; p<5; p++)
        for(int q=0; q<5; q++)
            if(array[p][q] > current)
                current = array[p][q];
    return current;
}