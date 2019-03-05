#include <stdio.h>

int Factorial_iter(int n);
int Factorial(int n);

int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    printf("iterative factorial : %d\n", Factorial_iter(n));
    printf("recursive factorial : %d\n", Factorial(n));


}
int Factorial_iter(int n)
{
    int fn=1;
    int i;
    for(i=1;i<=n;i++)
    {
        fn = fn*i;
    }
    return fn;
    
}
int Factorial(int n)
{
    if(n==1)
        return 1;
    else
        return n*Factorial(n-1);
}
