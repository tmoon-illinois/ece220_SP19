#include <stdio.h>
#include <stdlib.h> //malloc, free
#define TOTAL_PLAYER 20
typedef struct playerStruct
{
    char Name[50];
    char Team[30];
    int HR;
    int R;
    int RBI;
    double AVG;
    double WAR;
}player;

int readNewLines(char *filename);
int readFileToPlayer(player p[], int num, char *filename);
int PrintPlayer(player p[], int num);
int PrintPlayerMostHR(player p[], int num);
void quickSort(player array[], int start, int end);
int partition(player array[], int low, int high);
void swap(player *first, player *second);
int main()
{
//    player p[TOTAL_PLAYER];

    char filename[50] = "mlb_batter_2018.csv";
    int NumPlayer = readNewLines(filename);

    player *p = (player *) malloc(NumPlayer*sizeof(player));
    if(p==NULL)
    {
        printf("malloc failes\n");
        return -1;
    }


    readFileToPlayer(p, NumPlayer, filename);
    //PrintPlayer(p,num);
    PrintPlayerMostHR(p, NumPlayer);

    quickSort(p, 0, NumPlayer-1);
    PrintPlayer(p,NumPlayer);

    // add plyaer
    char newfilename[50] = "mlb_batter_2018_add.csv";
    int newNumPlayer = readNewLines(newfilename);

    player *temp;
    temp = realloc(p, (NumPlayer + newNumPlayer)*sizeof(player));
    //p = realloc(p,);

    if(temp == NULL)
    {
        printf("realloc fails \n");
        return -1;
    }
    else
    {

        p = temp;
        readFileToPlayer(p+NumPlayer, newNumPlayer, newfilename);

        quickSort(p, 0, NumPlayer+newNumPlayer-1);
        PrintPlayer(p,NumPlayer+newNumPlayer);

    }

    free(p);


}
int readFileToPlayer(player p[], int num, char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if( file == NULL)
    {
        printf("Cannot opern %s.\n", filename);
        return -1;
    }


    int i;

    char header[50];
    fgets(header, 50, file);

    for(i=0;i<num;i++)
    {
        fscanf(file, "%[^,],%[^,],%d,%d,%d,%lf,%lf\n", p[i].Name, p[i].Team, &p[i].HR, &p[i].R, &p[i].RBI, &p[i].AVG, &p[i].WAR);
    }
    fclose(file);
}
int PrintPlayer(player p[], int num)
{
    int i;
    printf("========================================================================\n");
    printf("%-5s%-20s%-20s%-5s%-5s%-5s%-8s%-8s\n", "#", "Name", "Team", "HR", "R", "RBI", "AVG", "WAR");
    printf("------------------------------------------------------------------------\n");

    for(i=0;i<num;i++)
        printf("%-5d%-20s%-20s%-5d%-5d%-5d%-8.3lf%-8.3lf\n", i+1, p[i].Name, p[i].Team, p[i].HR, p[i].R, p[i].RBI, p[i].AVG, p[i].WAR);
    printf("========================================================================\n\n\n");

}

int PrintPlayerMostHR(player p[], int num)
{
    int i;
    int maxHR = 0;
    int maxHR_ind = 0;

    for(i=0;i<num;i++)
    {
        if(maxHR < p[i].HR)
        {
            maxHR = p[i].HR;
            maxHR_ind = i;
        }
    }
    printf("%s hitted most HR (%d)\n", p[maxHR_ind].Name, maxHR);
}

void quickSort(player array[], int start, int end)
{
    if(start > end)
        return;


    int pivot_index = partition(array, start, end);
    quickSort(array, start, pivot_index-1);
    quickSort(array, pivot_index+1, end);
}

int partition(player array[], int low, int high)
{
    int i,j;
    int pivot = array[high].HR;

    i = low -1;

    for(j=low; j<high ; j++)
    {
        if(array[j].HR > pivot )
        {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[i+1], &array[high]);

    return i+1;
}

void swap(player *first, player *second)
{
    player temp;

    temp = *first;
    *first = *second;
    *second = temp;
}
int readNewLines(char *filename)
{
    FILE *file;

    int count = 0;
    char c;
    if( (file = fopen(filename, "r")) == NULL ){
        printf("Cannot open %s \n", filename);
        return -1;
    }
    for(c = getc(file); c!=EOF; c = getc(file))
    {
        if(c =='\n')
            count++;
    }


    fclose(file);
    return count;

}















