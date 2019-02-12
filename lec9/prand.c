#include <stdio.h>
#include <stdlib.h>

double GenRand(double a, double b);

int main()
{
    printf("Range of rand = [0 %d]\n", RAND_MAX);

    double a,b;
    printf("Enter a b : ");
    scanf("%lf %lf", &a, &b);

    int i;
    for(i=0; i<10; i++)
    {
        printf("%lf\n", GenRand(a,b));
    }
    return 0;
}

double GenRand(double a, double b)
{
    double result;

    result = rand()*(b-a)/RAND_MAX + a;

    return result;
}
