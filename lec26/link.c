#include <stdio.h>
#include <stdlib.h>

typedef struct Struct item;
struct Struct 
{
    int data;
    item *next;
};
/*
int additem(item **head, int input){
    item *newitem = (item*) malloc(sizeof(item));
    if(newitem == NULL) return 0;
    newitem->data = input;
    newitem->next = *head;
    *head = newitem;
    return 1;
}
*/
item *additem(item *head, int input){
    item *newitem = (item*) malloc(sizeof(item));
    if(newitem == NULL) return 0;
    newitem->data = input;
    newitem->next = head;
    head = newitem;
    return head;
}

void printitem(item *head){
    item *cursor = head;
    while(cursor != NULL){
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
}
int main(){
    item *head = NULL;
    //additem(&head,5);
    head = additem(head,5);
    printf("%p\n", head);
    //additem(&head,10);
    head = additem(head,10);
    printf("%p\n", head);
    printitem(head);
}
