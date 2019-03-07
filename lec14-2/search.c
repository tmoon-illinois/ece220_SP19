#include <stdio.h>
#define SIZE 6
void print_array(int array[], int n);
int linearSearch(int array[], int n, int key);
int binarySearch(int array[], int n, int key);
int binarySearch_rec(int array[], int key, int low, int high);
int main()
{
    int array[] = {11,12,22,25,32,66};
    int n = SIZE;

    int key;
    int found;

    print_array(array, SIZE);

    printf("ENter key value: ");
    scanf("%d", &key);

    //found = linearSearch(array,SIZE,key);
    found = binarySearch(array,SIZE,key);

    if(found ==-1)
        printf("Key is not found\n");
    else
        printf("Found key at index %d\n", found);

    found = binarySearch_rec(array,key, 0, n-1);
    if(found ==-1)
        printf("Rec: Key is not found\n");
    else
        printf("Rec: Found key at index %d\n", found);

}

void print_array(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%4d ", array[i]);

    printf("\n");
}

int linearSearch(int array[], int n, int key)
{
    int i;
    int cnt =0;

    for(i=0;i<n;i++)
    {
        cnt++;
        printf("linearSearch cnt = %d\n", cnt);
        if(array[i] == key)
            return i;
    }
    return -1;
}
int binarySearch(int array[], int n, int key)
{

    int low=0, high=n-1, mid;
    int cnt=0;
    
    while(low <= high)
    {
        cnt++;
        printf("binarySearch cnt = %d\n", cnt);
        mid = (low+high)/2;
        if(array[mid] == key)
            return mid;
        else if(array[mid] < key)
            low = mid + 1;
        else
            high = mid -1;
    }
    return -1;
}
int binarySearch_rec(int array[], int key, int low, int high)
{
    int mid;

    if(low > high)
        return -1;

    mid = (low+high)/2;
    if(array[mid] ==  key)
        return mid;
    else if(array[mid] < key)
        return binarySearch_rec(array, key, mid+1, high);
    else 
        return binarySearch_rec(array, key, low, mid-1);
}























