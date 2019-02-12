#include <stdio.h>
#include "myfun.h"

int main() 
{
    int number;
    long int answer;

    printHeader();
    printf("Enter a number: "); 
    scanf("%d", &number);

    answer = Fact(number);

    printf("factorial of %d is %ld\n", number, answer);
    return 0; 
}

