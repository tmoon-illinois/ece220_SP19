/*
 * Print nxn idendity matrix (input n from keyboard)
 */
#include <stdio.h>


int main()
{
    // row=i, column=j
    int i,j;
    // size of idendity matrix from keyboard
    int n;

//    int counter=0;

    // get input from keyboard
    printf("Enter the size of I-matrix: ");
    scanf("%d", &n);

    // print the result
    for(i=0; i<n ;i++)// loop for rows
    {
        for(j=0; j<n ; j++)// loop for columns
        {
            if (i==j)
            {
                printf("1 ");
                /*
                if(j==1)
                {
                    break;
                }
                */

            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
        /*
        if (i==1)
        {
            break;
        }
        */
    }
    return 0;

}
