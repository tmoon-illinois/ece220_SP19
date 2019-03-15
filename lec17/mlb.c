#include <stdio.h>
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

int readFileToPlayer(player p[], int num, char *filename);
int PrintPlayer(player p[], int num);
int PrintPlayerMostHR(player p[], int num);
void quickSort(player array[], int start, int end);
int partition(player array[], int low, int high);
void swap(player *first, player *second);
int main()
{
    player p[TOTAL_PLAYER];
    int num = TOTAL_PLAYER;

    char filename[50] = "mlb_batter_2018.csv";

    readFileToPlayer(p, num, filename);
    //PrintPlayer(p,num);
    PrintPlayerMostHR(p, num);

    quickSort(p, 0, TOTAL_PLAYER-1);
    PrintPlayer(p,num);


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
}
int PrintPlayer(player p[], int num)
{
    int i;
    for(i=0;i<num;i++)
        printf("%s,%s,%d,%d,%d,%lf,%lf\n", p[i].Name, p[i].Team, p[i].HR, p[i].R, p[i].RBI, p[i].AVG, p[i].WAR);
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
        if(array[j].HR < pivot )
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















