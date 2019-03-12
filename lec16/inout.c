#include <stdio.h>
#define SIZE 20
int main()
{
    FILE *infile;
    FILE *outfile;

    char buffer[SIZE];

    long int pos;


    if( (infile = fopen("inputfile.txt", "r")) == NULL)
    {
        printf("Cannot open inputfile\n");
        return -1;
    }
    if( (outfile = fopen("outputfile.txt", "w")) == NULL)
    {
        printf("Cannot open outputfile\n");
        return -2;
    }

    pos = ftell(infile);
    printf("pos = %ld\n", pos);
    printf("infile pointer = %p\n", infile);


    while( fgets(buffer, SIZE, infile) != NULL  )
    {
        pos = ftell(infile);
        printf("pos = %ld\n", pos);
        printf("infile pointer = %p\n", infile);
        //printf("%s", buffer);
        fputs(buffer, outfile);
    }
    fclose(infile);
    fclose(outfile);

    return 0;


}
