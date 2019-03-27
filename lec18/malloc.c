#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr = (int *) malloc(sizeof(int));
    if(ptr==NULL){
        printf("Error - malloc failure\n");
        return -1;
    }
    *ptr = 10;
    printf("ptr value: %d, address: %p\n", *ptr, ptr);

    int *ptr2 = (int *) malloc(sizeof(int));
    *ptr2 = 5;
    printf("ptr2 value: %d, address: %p\n", *ptr2, ptr2);

    ptr = ptr2;
    printf("ptr value: %d, address: %p\n", *ptr, ptr);
    printf("ptr2 value: %d, address: %p\n", *ptr2, ptr2);
    free(ptr);
    free(ptr2);// <- Error
}
