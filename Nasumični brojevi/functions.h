#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _Number;
typedef struct _Number* NumberP;
typedef struct _Number{
    int number;
    NumberP next;
}Number;

int CreateNew(NumberP head);

int Insert(NumberP head, NumberP new);

int Print(NumberP head);

int DeleteAfter(NumberP prev);

int Remove(NumberP head);

int WriteSorted(NumberP head);

#endif