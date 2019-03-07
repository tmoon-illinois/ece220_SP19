#include <stdio.h>

int Factorial(int n);
int Factorial_iter(int n);
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Recursive F: %d\n", Factorial(n));
    printf("Iterative F: %d\n", Factorial_iter(n));

}
int Factorial(int n)
{
    if(n==1)
        return 1;
    else
        return n*Factorial(n-1);
}
int Factorial_iter(int n)
{
    int i;
    int fn=1;

    for(i=1; i<=n ;i++)
    {
        fn = fn * i;
    }
    return fn;
}
