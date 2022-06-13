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


unsigned char RightRotating (unsigned char mask, int k){
    int lastK = mask & ((1 << k) - 1);
    unsigned char ans = (mask >> k) | (lastK << (8 - k));
    return ans;
}

/*
1>>1 = 00000010      
*/
int main(){

    unsigned char x = 54;
    printf( "%d = %s\n", x,  intToBinary(x,8).str);

    for (int i = 0; i < 8; i++)
    {
        unsigned char R = RightRotating(x, i);
        printf("Rotate %d: %s\n", i, intToBinary(R, 8).str);
    }

    return 0;
}