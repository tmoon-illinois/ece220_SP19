#include <stdio.h>
#define SIZE 5
void print_array(int array[], int n);
void bubbleSort(int array[], int n);
void insertSort(int array[], int n);
int main()
{
    int array[] = { 3,9, 20, 25, 29};
    print_array(array,SIZE);
    bubbleSort(array,SIZE);
    //insertSort(array,4);
    
    print_array(array,SIZE);

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
    int cnt=0;

    do{
        swapped = 0;
        for(i=0; i<n-1 ;i++)
        {
            cnt++;
            if(array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = 1;
            }
        }
    }while(swapped != 0 );
    printf("bubble sort cnt = %d\n", cnt);
}
void insertSort(int array[], int n)
{

    int unsorted, sorted, key;

    int cnt =0;
    for(unsorted = 1; unsorted <n ; unsorted++)
    {
        key = array[unsorted];
        for(sorted = unsorted-1; sorted >=0 ; sorted--)
        {
            cnt++;
            if(array[sorted] > key)
            {
                array[sorted+1] = array[sorted];
            }
            else
            {
                break;
            }
        }
        array[sorted+1] = key;
    }

    printf("insterion sort cnt = %d\n", cnt);
}

















