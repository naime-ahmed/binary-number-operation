#include<stdio.h>
#include<float.h> 
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

struct Binary
{
    char str[50];
};

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

struct Binary intToBinary(unsigned int val, int k){

    struct Binary ans;
    int idx = 0;
    while (val > 0)
    {
        int d = val % 2;
        val = val / 2;
        ans.str[idx] = '0' + d;
        idx++;
    }

    for (int i = idx; i < k; i++) // value of 8 will be change depend on data type
    {
        ans.str[i] = '0';
        idx++;
    }

    for (int i = 0, j=1; i < idx/2; i++, j++)
    {
        swap(&ans.str[i], &ans.str[idx - j]);
    }
    // printf( "%d\n", idx );

    ans.str[k] = '\0';
    return ans;
}

bool getBit(unsigned int mask, int k){
    return (mask & (1 << k)) != 0;
}

unsigned int setBit(unsigned int mask, int k){
    return mask | (1 << k);
}

unsigned int clearBit(unsigned int mask, int k){
    return mask & ~(1 << k);
}

unsigned int flipBit(unsigned int mask, int k){
    return mask ^ (1 << k);
}

int main(){

    int num = 54, bit = 8;;

    struct Binary binArr;
    binArr = intToBinary(num, bit);

    printf( "%s\n", binArr.str );

    for (int i = 0; i < bit; i++)
    {
        printf( "%d th bit: %d\n", i, getBit(num,i) );
        printf("set bit: %s\n",  intToBinary(setBit(num, i), bit).str);
        printf("clear bit: %s\n",  intToBinary(clearBit(num, i), bit).str);
        printf("Flip bit: %s\n", intToBinary(flipBit(num, i), bit).str);
    }

    return 0;
}

/*
    int X;

    get ith bit
    set ith bit     -> make 1
    clear ith bit   -> make 0
    flip ith bit    -> 0 -> 1, 1 -> 0
*/