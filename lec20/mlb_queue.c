#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc, free
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

player *front, *end;

void enqueue(player *Data);
player dequeue();
void readFileToPlayer_queue(player *head, int num, char *filename);

player* removeAll(player *head);
player* removePlayer(player *head, player *target);
player* insert_after(player *head, player *prev, player *data);
player* searchName(player *head, char *name);
player* append(player *head, player *Data);
player* createPlayer(player *next, player *Data);
player* prepend(player *head, player *Data);
int readFileToPlayer_prepend(player **head, int num, char *filename);
player* readFileToPlayer_append(player *head, int num, char *filename);
int readNewLines(char *filename);
void PrintPlayer(player *head);
void PrintPlayerMostHR(player *head);
void quickSort(player array[], int start, int end);
int partition(player array[], int low, int high);
void swap(player *first, player *second);

int main()
{
    // add plyaer from csv
    char filename[50] = "mlb_batter_2018.csv";
    int NumPlayer = readNewLines(filename);
 
    front = NULL;
    end = NULL;
    // add players from the file
    readFileToPlayer_queue(front, NumPlayer, filename);
    PrintPlayer(front);
    PrintPlayerMostHR(front);

    // pop one player
    player Data = dequeue();
    printf(">>> Popped player\n");
    printf("%-20s%-20s%-5s%-5s%-5s%-8s%-8s\n", "Name", "Team", "HR", "R", "RBI", "AVG", "WAR");
    printf("%-20s%-20s%-5d%-5d%-5d%-8.3lf%-8.3lf\n", Data.Name, Data.Team, Data.HR, Data.R, Data.RBI, Data.AVG, Data.WAR);
    PrintPlayer(front);

    // push one player
    player *temp = (player*) calloc(1,sizeof(player));
    strcpy(temp->Name, "aaa");
    enqueue(temp);
    PrintPlayer(front);

    return 0;
}
void enqueue(player *Data)
{
    player *new = createPlayer(NULL, Data);
    if(front == NULL){ // queue is empty
        front = new;
        end = front;
    }
    else{
        end->next = new;
        end = new;
    }
}
player dequeue()
{
    if(front == NULL) // queue is empty
        return;

    player Data;
    player *temp = front->next;
    strcpy(Data.Name, front->Name);
    strcpy(Data.Team, front->Team);
    Data.HR = front->HR;
    Data.R = front->R;
    Data.RBI = front->RBI;
    Data.AVG= front->AVG;
    Data.WAR = front->WAR;


    if(front == end) // queue has only 1 item
        end = NULL;
    free(front);
    front = temp;
    if(front == NULL) // queue is empty after dequeue
        end = NULL;

    return Data;
}
void readFileToPlayer_queue(player *top, int num, char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if( file == NULL)
    {
        printf("Cannot opern %s.\n", filename);
        return;
    }
    int i;
    char header[50];
    player *temp = (player*) malloc(sizeof(player));

    fgets(header, 50, file);
    for(i=0;i<num;i++)
    {
        fscanf(file, "%[^,],%[^,],%d,%d,%d,%lf,%lf\n", temp->Name, temp->Team, &(temp->HR), &(temp->R), &(temp->RBI), &(temp->AVG), &(temp->WAR));
        enqueue(temp);
    }
    fclose(file);
    free(temp);

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
    player *temp = (player*) malloc(sizeof(player));

    fgets(header, 50, file);
    for(i=0;i<num;i++)
    {
        fscanf(file, "%[^,],%[^,],%d,%d,%d,%lf,%lf\n", temp->Name, temp->Team, &(temp->HR), &(temp->R), &(temp->RBI), &(temp->AVG), &(temp->WAR));
        head = append(head, temp);
    }
    fclose(file);

    return head;
}
int readFileToPlayer_prepend(player **head, int num, char *filename)
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
    player *temp = (player*) malloc(sizeof(player));

    fgets(header, 50, file);
    for(i=0;i<num;i++)
    {
        fscanf(file, "%[^,],%[^,],%d,%d,%d,%lf,%lf\n", temp->Name, temp->Team, &(temp->HR), &(temp->R), &(temp->RBI), &(temp->AVG), &(temp->WAR));
        *head = prepend(*head,temp);
        printf("head=%p\n", *head);
    }
    fclose(file);

    return 0;
}
player* createPlayer(player *next, player *Data)
{
    player *newPlayer = (player *) malloc(sizeof(player));
    if(newPlayer==NULL){
        printf("Error: cannot allocate a new player\n");
        exit(1);
    }
    strcpy(newPlayer->Name, Data->Name);
    strcpy(newPlayer->Team, Data->Team);
    newPlayer->HR = Data->HR; 
    newPlayer->R = Data->R; 
    newPlayer->RBI = Data->RBI; 
    newPlayer->AVG = Data->AVG; 
    newPlayer->WAR = Data->WAR; 

    newPlayer->next = next;

    return newPlayer;

}
player* prepend(player *head, player *Data)
{
    player *newPlayer = createPlayer(head, Data);
    head = newPlayer;
    return head;
}
player* append(player *head, player *Data)
{
    player *cursor = head;

    if(cursor == NULL)
        head = createPlayer(NULL, Data);
    else{
        while(cursor->next != NULL)
            cursor = cursor->next;

        player *newPlayer = createPlayer(NULL, Data);
        cursor->next = newPlayer;
    }
    return head;
}

player* searchName(player *head, char *name)
{
    player *cursor = head;
    while(cursor != NULL){
        if( strcmp(cursor->Name, name) == 0)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}

player* insert_after(player *head, player *prev, player *data)
{

    player *cursor = head;
    while(cursor != prev)
        cursor = cursor->next;
    
    if(cursor == NULL){
        printf("cannot find the player.\n");
    }
    else{
        player *newplayer = createPlayer(cursor->next, data);
        cursor->next = newplayer;
    }
    return head;

}
player* removeAll(player *head)
{
    player *cursor = head, *temp;
    if(head != NULL){
        while(cursor !=NULL){

            printf("Free %s\n", cursor->Name);
            temp = cursor->next;
            free(cursor);
            cursor = temp;
        }
    }
    return NULL;
}
player* removePlayer(player *head, player *target)
{
    player *cursor = head;
    if(target == NULL){
        printf("Invalid target player.\n");
        return head;
    }
    if(target == head){

        head = head->next;
        free(target);
        return head;
    }
    while(cursor != NULL)
    {
        if(cursor->next == target)
            break;
        cursor= cursor->next;
    }
    if(cursor== NULL){
        printf("cannot find the player.\n");
    }
    else{
        cursor->next = target->next;
        free(target);
    }
    return head;
}
void PrintPlayer(player *head)
{
    int i=0;
    player *current = head;
    printf("========================================================================\n");
    printf("%-5s%-20s%-20s%-5s%-5s%-5s%-8s%-8s\n", "#", "Name", "Team", "HR", "R", "RBI", "AVG", "WAR");
    printf("------------------------------------------------------------------------\n");
    while(current != NULL){
        printf("%-5d%-20s%-20s%-5d%-5d%-5d%-8.3lf%-8.3lf\n", i+1, current->Name, current->Team, current->HR, current->R, current->RBI, current->AVG, current->WAR);
        current = current->next;
        i++;
    }
    printf("========================================================================\n\n\n");
}

void PrintPlayerMostHR(player *head)
{
    int i;
    int maxHR = 0;
    player *max;
    player *cursor = head;

    while(cursor != NULL)
    {
        if(maxHR < cursor->HR)
        {
            maxHR = cursor->HR;
            max = cursor;
        }
        cursor = cursor->next;
    }
    printf("%s hitted most HR (%d)\n", max->Name, max->HR);
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















