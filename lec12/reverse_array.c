#include <stdio.h>

void array_reverse(int array[], int n);
void print_array(int array[], int n);

int main()
{
    int n;

    printf("Enter size of array n: ");
    scanf("%d", &n);

    int array[n];
    int i;

    printf("Enter each element of array \n");
    for(i=0;i<n;i++)
    {
        printf("Input %d-th element: ",i);
        scanf("%d", &array[i]);
    }

    printf("Before reverse\n");
    print_array(array, n);

    printf("After reverse\n");
    array_reverse(array, n);
    print_array(array, n);
    return 0;
}

void array_reverse(int array[], int n)
{
    int i;
    int temp;
    for(i=0;i<(n/2);i++)
    {
        temp = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = temp;
    }
}

void print_array(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
