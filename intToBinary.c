#include<stdio.h>
#include<float.h> 
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void intToBinary(unsigned int val, char str[]){

    int idx = 0;
    while (val > 0)
    {
        int d = val % 2;
        val = val / 2;
        str[idx] = '0' + d;
        idx++;
    }

    for (int i = idx; i < 8; i++) // value of 8 will be change depend on data type
    {
        str[i] = '0';
        idx++;
    }

    for (int i = 0, j=1; i < idx/2; i++, j++)
    {
        swap(&str[i], &str[idx - j]);
    }
    // printf( "%d\n", idx );

    str[idx] = '\0';
}

// what is the specialty of unsigned keyword??
int main(){

    char str[100];
    unsigned int v = 0.78125;
    intToBinary(v, str);
    printf( "%s\n", str );

    return 0;
}