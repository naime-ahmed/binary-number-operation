#include<stdio.h>
#include<float.h> 
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

// binary to decimal conversion.
unsigned int binaryToInt(char str[]){
    int len = strlen(str);

    unsigned int ans = 0;
    for (int i = len - 1, p2 = 1; i >= 0; i--, p2 *= 2)
    {
        int bit = str[i] - '0';
        // printf("%d %d %d\n", i, p2, bit);
        if (bit == 1)
        {
            ans += p2;
        }
    }
    return ans;
}

// method 2
unsigned int method2(char str[]){
    int len = strlen(str);

    unsigned int ans = 0;
    for (int i = 0; i<len; i++)
    {
        int bit = str[i] - '0';
        // printf("%d %d %d\n", i, p2, bit);

        ans = ans* 2 + bit;
        // printf( "%d\n", ans ); // debug purpose

    }

    return ans;
}


int main(){

    // // binary to int
    // char str[100];
    // // fgets(str, 100, stdin);
    // scanf( "%s", &str );

    // printf( "%d\n", binaryToInt(str) );


    // method 2
    char num[100];
    scanf( "%s", &num );
    printf( "%d\n", method2(num) );

    return 0;
}