#include <stdio.h>
#define BUF_SIZE 4
int main()
{
    char input[BUF_SIZE];
    char a='a';

    fgets(input, BUF_SIZE, stdin);
    //scanf("%s",input);

    printf("%s\n",input);
    printf("%c\n",a);
/*
    int rc;
    int num1, num2;
    char str[20];

    rc = sscanf(input, "%d%d%s", &num1, &num2, str);

    printf("rc=%d\n", rc);
    printf("num1 = %d, num2 = %d, str = %s\n", num1, num2, str);
*/
}
