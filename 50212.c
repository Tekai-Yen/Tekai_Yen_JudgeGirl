#include<stdio.h>
#include<assert.h>

/*void print(int binary[]){
    for(int p=0; p<32; p++){
        printf("%d", binary[p]);
        if(p == 15) printf("  ");
        if(p == 7 || p == 23)printf(" ");
    }
    printf("\n");
}*/

void transform(int binary[], int number, int l, int r){
    if(number == 1) return;
    int count = 0, temp;
    for(int p=l; p<=r; p++)
        count += (binary[p] == 1)?1:0;
    if(count % 2 == 1){
        for(int p=0; p<number/2; p++){
            temp = binary[l+p];
            binary[l+p] = binary[l+number/2+p];
            binary[l+number/2+p] = temp;
        }
    }
    //printf("L=%2d, R=%2d, count=%2d  ", l, r, count);
    //print(binary);
    transform(binary, number/2, l, l+number/2-1);
    transform(binary, number/2, l+number/2, r);
}

int main()
{
    unsigned int data, binary[32], power = 31;
    scanf("%u", &data);
    for(int p=31; p>=0; p--){
        binary[p] = data % 2;
        data /= 2;
    }
    assert(data == 0);
    /*for(int p=0; p<32; p++){
        printf("%d", binary[p]);
    }*/
    //print(binary);
    transform(binary, 32, 0, 31);
    for(int p=0; p<32; p++){
        data += binary[p] * (1 << power);
        power--;
    }
    //print(binary);
    printf("%u", data);
    return 0;
}