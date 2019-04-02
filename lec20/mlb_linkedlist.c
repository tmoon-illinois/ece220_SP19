#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc, free
#define TOTAL_PLAYER 20
typedef struct playerStruct player;
struct playerStruct
{
    char Name[50];
    char Team[30];
    int HR;
    int R;
    int RBI;
    double AVG;
    double WAR;
    player *next;
};
player* removeALL(player *head);
player* removePlayer(player *head, player *target);
void insertPlayer(player *head, player *prev, player *Data);
player* searchName(player *head, char *name);
player* appendPlayer(player *head, player *Data);
player* createPlayer(player *next, player *Data);
int readNewLines(char *filename);
player* readFileToPlayer_append(player *head, int num, char *filename);
int readFileToPlayer(player p[], int num, char *filename);
int PrintPlayer(player *head);
int PrintPlayerMostHR(player p[], int num);
void quickSort(player array[], int start, int end);
int partition(player array[], int low, int high);
void swap(player *first, player *second);
int main()
{
//    player p[TOTAL_PLAYER];

    char filename[50] = "mlb_batter_2018.csv";
    int NumPlayer = readNewLines(filename);

    player *head = NULL;
    head = readFileToPlayer_append(head, NumPlayer, filename);
    PrintPlayer(head);

    char str[50];
    printf("Endter a player name to search: ");
    scanf("%[^\n]%*c", str);
    player *key;
    key = searchName(head, str);

    if(key == NULL)
        printf("No player found\n");
    else
        printf("Found %s in the list \n", key->Name);


    player *Data = (player*) calloc(1,sizeof(player));;
    printf("Enter a new player name: ");
    scanf("%[^\n]%*c", Data->Name);

    
    insertPlayer(head, key, Data);
    PrintPlayer(head);
    free(Data);


    printf("Endter a player name to remove: ");
    scanf("%[^\n]%*c", str);
    key = searchName(head, str);
    head = removePlayer(head, key);
    PrintPlayer(head);


    head = removeALL(head);
    PrintPlayer(head);



/*
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
*/

}
player* readFileToPlayer_append(player *head, int num, char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if( file == NULL)
    {
        printf("Cannot opern %s.\n", filename);
        return NULL;
    }
    int i;

    char header[50];
    fgets(header, 50, file);

    player *Data = (player*) malloc(sizeof(player));
    for(i=0;i<num;i++)
    {
        fscanf(file, "%[^,],%[^,],%d,%d,%d,%lf,%lf\n", Data->Name, Data->Team, &(Data->HR), &(Data->R), &(Data->RBI), &(Data->AVG), &(Data->WAR));

        head = appendPlayer(head, Data);
    }
    fclose(file);
    free(Data);

    return head;

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
int PrintPlayer(player *head)
{
    int i=0;
    printf("========================================================================\n");
    printf("%-5s%-20s%-20s%-5s%-5s%-5s%-8s%-8s\n", "#", "Name", "Team", "HR", "R", "RBI", "AVG", "WAR");
    printf("------------------------------------------------------------------------\n");

    player *cursor = head;

    while(cursor != NULL){

        printf("%-5d%-20s%-20s%-5d%-5d%-5d%-8.3lf%-8.3lf\n", i+1, cursor->Name, cursor->Team, cursor->HR, cursor->R, cursor->RBI, cursor->AVG, cursor->WAR);
        cursor = cursor->next;
        i++;
    }
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

player* createPlayer(player *next, player *Data)
{
    player *new = (player*) malloc(sizeof(player));
    

    strcpy(new->Name, Data->Name);
    strcpy(new->Team, Data->Team);
    new->HR = Data->HR;
    new->R = Data->R;
    new->RBI = Data->RBI;
    new->AVG= Data->AVG;
    new->WAR = Data->WAR;

    new->next = next;

    return new;
}

player* appendPlayer(player *head, player *Data)
{
    player *cursor = head;
    if(cursor == NULL) // linked list is empty
        head = createPlayer(NULL, Data);
    else{
        while(cursor->next != NULL)
            cursor = cursor->next;

        player *new = createPlayer(NULL, Data);
        cursor->next = new;
    }

    return head;
}

player* searchName(player *head, char *name)
{
    player *cursor = head;
    while( cursor !=NULL){
        if( strcmp(cursor->Name, name) == 0 )
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}

void insertPlayer(player *head, player *prev, player *Data)
{
    player *cursor = head;
    while(cursor != prev)
        cursor = cursor->next;

    if(cursor == NULL){
        printf("cannot find prev node\n");

    }
    else{
        player *new = createPlayer(cursor->next, Data);
        cursor->next = new;
    }
}

player* removePlayer(player *head, player *target)
{
    player *cursor = head;

    if(target == NULL){
        printf("Target is not valid\n");
        return head;
    }
    if(target == head){
        head = head->next;
        free(target);
        return head;
    }
    while(cursor != NULL){
        if(cursor->next == target)
            break;
        cursor = cursor->next;
    }

    if(cursor == NULL)
        printf("Cannot find the target\n");
    else
    {
        cursor->next = target->next;
        free(target);
    }

    return head;
}

player* removeALL(player *head)
{
    player *cursor = head;
    player *temp;
    if(head == NULL)
        return NULL;
    else
    {
        while(cursor != NULL){
            printf("freed player name %s\n", cursor->Name);
            temp = cursor->next;
            free(cursor);
            cursor = temp;
        }
        return NULL;
    }
}








