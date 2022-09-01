#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

struct _Student;
typedef struct _Student* StudentP;
typedef struct _Student{
    char name[MAX];
    char surname[MAX];
    int id;
    StudentP next;
}Student;

int Read(char fileName[], StudentP head);

StudentP CreateNewElement(char name[], char surname[]);

int Insert(StudentP head, StudentP new);

int InsertAfter(StudentP prev, StudentP new);

int Print(StudentP head);

int DeleteAll(StudentP head);

int DeleteAfter(StudentP prev);

int RemoveByName(StudentP head);

int FindDivisible(StudentP head);

StudentP CopyElement(char name[], char surname[], int id);

#endif