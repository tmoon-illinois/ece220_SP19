#include <stdio.h>
#include <ctype.h>

int main()
{
    printf("isalpha('a') = %d\n", isalpha('a'));
    printf("isalpha(1) = %d\n", isalpha(1));
    printf("toupper('a') = %c\n", toupper('a'));

    char in;
    printf("Enter a character: ");
    in = getchar();
    printf("You entered ");
    putchar(in);
    printf("\n");

    if(isalpha(in) != 0)
        printf("It was an alphabet\n");

    else if(isdigit(in) !=0)
        printf("It was a number\n");
    else
        printf("It was something else\n");


    return 0;
}


