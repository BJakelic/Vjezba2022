#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

struct _Article;
typedef struct _Article* ArticleP;
typedef struct _Article{
    char category[MAX];
    char name[MAX];
    int amount;
    ArticleP next;
}Article;

int Read(char fileName[], ArticleP head);

int RemoveArticlesFromReceipt(ArticleP headA, ArticleP headR);

ArticleP CreateNew(char category[], char name[], int amount);

int Insert(ArticleP new, ArticleP head);

int InsertAfter(ArticleP new, ArticleP prev);

int Print(ArticleP head);

int DeleteAll(ArticleP head);

#endif