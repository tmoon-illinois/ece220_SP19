/*
 * Search for the substring "the"
 */

#include <stdio.h>


int main()
{
    char keyin; // input from keyboard
    int state = 0;
    int counter = 0;

    printf("Enter a string: ");

    do{
        // key type form keyboard
        scanf("%c", &keyin);

        switch(state){
            case 0:
                if(keyin == 't')
                {
                    state = 1;
                }
                break;
            case 1:
                if(keyin == 'h')
                {
                    state = 2;
                }
                else if(keyin == 't')
                {
                    state = 1;
                }
                else
                {
                    state = 0;
                }
                break;
            case 2:
                if(keyin == 'e')
                {
                    state = 0;
                    counter++; //counter = counter + 1;
                }
                else if(keyin == 't')
                {
                    state = 1;
                }
                else
                {
                    state = 0;
                }
                break;
            default:
                printf("Invalid state \n");
                break;
        }
    }while(keyin != '\n');
    printf("Number of matches = %d\n", counter);

    return 0;
}
