#include <stdio.h>

int main()
{
    char word[10] = "ABCDEFGHI";
    char *cptr;

    cptr = word; // points to word[0]

    printf("cptr = %X, word = %X, &word[0] = %X\n", cptr, word, &word[0]);
    printf("cptr+1 = %X, word+1 = %X, &word[1] = %X\n", cptr+1, word+1, &word[1]);
    printf("*cptr = %c, *word = %c, word[0] = %c\n", *cptr, *word, word[0]);
    printf("*(cptr+5) = %c, *(word+5) = %c, word[5] = %c\n", *(cptr+5), *(word+5), word[5]);


    cptr = cptr + 1;
    //word = word + 1; // illigal
    printf("*cptr = %c, *word = %c, word[0] = %c\n", *cptr, *word, word[0]);

    return 0;

}

