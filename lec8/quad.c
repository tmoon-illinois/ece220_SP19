/*
 * Calculate the (real) solution of the quadratic equation a*x^2 + b*x + c = 0
 */
#include <stdio.h>
#include <math.h>   // for sqrt

int main()
{
    float a,b,c;    // coefficients
    float D;        // determinant
    float x1,x2;    // solution(s)

    // get equation coefficients
    printf("Enter coefficients a b c: ");
    scanf("%f %f %f", &a, &b, &c);

    printf("Solving equation %f*x^2 + %f*x + %f = 0\n", a, b, c);

    // compute the solution and print the results
    D = b*b - 4*a*c;

    if(D==0)
    {
        x1 = -b/(2*a);
        printf("x1 = %f\n", x1);
    }
    else if(D>0)
    {
        x1 = (-b + sqrt(D))/(2*a);
        x2 = (-b - sqrt(D))/(2*a);
        printf("x1 = %f, x2 = %f\n", x1, x2);
    }
    else
    {
        printf("No real solutions\n");
    }

    return 0;

}
