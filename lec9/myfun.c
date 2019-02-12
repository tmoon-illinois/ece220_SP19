#include "myfun.h"
long int Fact(int n) 
{
    int i;
    long int result=1; // 32bit->64bit


    for (i = 1; i <= n; i++)
    {
        result = result * i;//1*2*3
    }

    return result;  
}

void printHeader(void)
{
    printf("=================================\n");
}
