#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1024

struct _Stud;
typedef struct _Stud* StudP;
typedef struct _Stud{
    char name[MAX];
    char surname[MAX];
    int grade;
    StudP next;
}Stud;

int Read(char fileName[], StudP head);

StudP CreateNew(char name[], char surname[]);

int Insert(StudP head, StudP new);

int InsertAfter(StudP prev, StudP new);

int Print(StudP head);

int DeleteAll(StudP head);

int DeleteAfter(StudP prev);

int DeleteByGrade(StudP head);

#endif