
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void copy_str(char des[], char src[]);
int main()
{
    char des[MAX_SIZE], src[MAX_SIZE];
    fgets(src, MAX_SIZE, stdin);

    //des = src; //illiegal
    //copy_str(des,src);
    //sscanf(src, "%s", des);
    strcpy(des,src);

    printf("srd: %s", src);
    printf("des: %s", des);
}
void copy_str(char des[], char src[])
{
    int i=0;

    while(src[i] != '\0')
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
    
}
