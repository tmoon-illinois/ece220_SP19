/*
 * Write a C program to calculate the total amount to pay including tip. 
 */

// preprocessor directives
#include <stdio.h>
#define TIP 0.18

int main()
{
    // declare floating-point variables (total, bill)
    float total,bill;
    //float bill;


    // prompt user to enter the amount of bill
    printf("Enter your bill ");
    scanf("%f", &bill);

    // calculate the total amount
    total = bill*TIP + bill;

    // print the result
    printf("The total is $%.2f\n", total);

    // return
    return 0;
}
