#include <stdio.h>

#define MAX_NUM 10

double average(int array[]);
//double average(int *array);
//double average(int array[MAX_NUM]);

int main()
{
    int array[MAX_NUM];
    int *ptr;
    double result;

    ptr = array;

    int i;


    for(i=0; i<MAX_NUM ; i++)
    {
        array[i] = i+1;// 1,2,3,....10 = 55, average = 5.5 
    }

    result = average(array); 
    //ptr = ptr + 1; //address of second element
    //result = average(ptr); 

    printf("result = %lf\n", result);
    return 0;
}

double average(int array[])
//double average(int *array)
//double average(int array[MAX_NUM])
{
    int i;
    double sum=0;
    for(i=0; i<MAX_NUM ; i++)
    {
        sum = sum + array[i]; 
    }
    return sum/MAX_NUM;
}
