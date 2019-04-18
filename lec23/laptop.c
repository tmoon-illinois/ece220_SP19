#include <stdio.h>
typedef struct StructLaptop{
    int screenSize;
    int RAM;
    int power;
}laptop;
void powerON(laptop *p){
    p->power = 1;
}
void powerOFF(laptop *p){
    p->power = 0;
}
void printStatus(laptop *p){
    printf("Screen size: %d, RAM: %d, Power: %d\n", p->screenSize, p->RAM, p->power);
}
int main(){
    laptop mylaptop = {12, 8, 0};
    laptop *p = &mylaptop;

    powerON(p);
    printStatus(p);
    
    powerOFF(p);
    printStatus(p);

    p->power = 1;
    printStatus(p);
}
