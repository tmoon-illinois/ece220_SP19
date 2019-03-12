#include <stdio.h>
#define SIZE 5
int main()
{
    FILE *myfile;
    char buffer[SIZE];

    myfile = fopen("str.txt", "w");
    if(myfile == NULL)
    {
        printf("cannot open the file\n");
        return -1;
    }

    printf("Enter a string: ");
    fgets(buffer, SIZE, stdin);
    //scanf("%s", buffer);

    fputs("The input from keyboard\n", myfile);
    fputs(buffer, myfile);

    fclose(myfile);
}
