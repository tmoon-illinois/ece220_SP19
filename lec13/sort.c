#include <stdio.h>

void print_array(int array[], int n);
void bubbleSort(int array[], int n);
void insertSort(int array[], int n);
int main()
{
    int array[] = {21, 3, 23 ,9};
    print_array(array,4);
    bubbleSort(array,4);
    
    print_array(array,4);

}

void print_array(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%4d ", array[i]);

    printf("\n");
}
void bubbleSort(int array[], int n)
{
    int i;
    int swapped;
    int temp;

    do{
        swapped = 0;
        for(i=0; i<n-1 ;i++)
        {
            if(array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = 1;
            }
        }
    }while(swapped != 0 );
}
void insertSort(int array[], int n)
{
}

