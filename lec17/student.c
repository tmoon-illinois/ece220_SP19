#include <stdio.h>

//typedef union StudentStruct
typedef struct StudentStruct
{
    char Name[20];//pad 2byte
    int UIN;//4byte, pad 4byte =>32byte
    double GPA;//8byte
}student;

int main()
{
    //typedef struct StudentStruct student;
    //student s1 = {"AAA",0,0.00};
    
   // printf("Name: %s, UIN:%d, GPA:%lf\n", s1.Name, s1.UIN, s1.GPA);
/*
    student s1;
    printf("char=%d, int=%d, double=%d\n", sizeof(char), sizeof(int), sizeof(double));

    printf("student=%d\n", sizeof(student));
    s1.UIN = 123;
    s1.GPA = 3.00;
    printf("Name: %s, UIN:%d, GPA:%lf\n", s1.Name, s1.UIN, s1.GPA);

    */
    student ece220[100];
    ece220[0].UIN = 1;
    ece220[1].UIN = 2;


    student *ptr;
    ptr = &ece220[1];
    ptr++;
    ptr->UIN = 3;

    printf(" UIN of first student :%d, UIN of second student:%d, , UIN of third student:%d\n", ece220[0].UIN, ece220[1].UIN, ece220[2].UIN);
}
