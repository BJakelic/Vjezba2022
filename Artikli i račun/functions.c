#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int Read(char fileName[], ArticleP head)
{
    FILE* fp = NULL;
    char category[MAX] = {0};
    char name[MAX] = {0};
    int amount = 0;
    ArticleP new = NULL;
    
    fp = fopen(fileName, "r");
    if(!fp)
    {
        perror("Couldn't read file!");
        return EXIT_FAILURE;
    }
    
    while(!feof(fp))
    {
        fscanf(fp, "%s %s %d\n", category, name, &amount);
        new = CreateNew(category, name, amount);
        if(new)
        {
            Insert(new, head);
        }
    }
    
    fclose(fp);
    
    return EXIT_SUCCESS;
}

int RemoveArticlesFromReceipt(ArticleP headA, ArticleP headR)
{
    ArticleP tempA = headA;
    ArticleP tempR = NULL;
    
    while(tempA->next)
    {
        tempR = headR;
        
        while(tempR->next)
        {
            if(strcmp(tempA->next->name, tempR->next->name) == 0)
            {
                if(tempA->next->amount < tempR->next->amount)
                {
                    printf("WARNING!\nNot enough units of item: %s\n\n", tempA->next->name);
                    tempA->next->amount = 0;
                }
                else
                {
                    tempA->next->amount = tempA->next->amount - tempR->next->amount;
                }
            }
            
            tempR = tempR->next;
        }
        
        tempA = tempA->next;
    }
    
    return EXIT_SUCCESS;
}

ArticleP CreateNew(char category[], char name[], int amount)
{
    ArticleP new = NULL;
    new = (ArticleP)malloc(sizeof(Article));
    if(!new)
    {
        perror("Couldn't allocate memory!");
        return NULL;
    }
    
    strcpy(new->category, category);
    strcpy(new->name, name);
    new->amount = amount;
    new->next = NULL;
    
    return new;
}

int Insert(ArticleP new, ArticleP head)
{
    ArticleP temp = head;
    
    while(temp->next && strcmp(temp->next->category, new->category) < 0)
    {
        temp = temp->next;
    }
    
    InsertAfter(new, temp);
    
    return EXIT_SUCCESS;
}

int InsertAfter(ArticleP new, ArticleP prev)
{
    if(!new || !prev)
    {
        return EXIT_FAILURE;
    }
    
    new->next = prev->next;
    prev->next = new;
    
    return EXIT_SUCCESS;
}

int Print(ArticleP head)
{
    ArticleP temp = head;
    
    while(temp->next)
    {
        if(temp->next->amount < 5)
        {
            printf("%s %s %d\n", temp->next->category, temp->next->name, temp->next->amount);
        }
        
        temp = temp->next;
    }
    
    printf("\n-------------------------------------\n\n");
    
    return EXIT_SUCCESS;
}

int DeleteAll(ArticleP head)
{
    ArticleP temp = NULL;
    
    while(head->next)
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
    
    printf("DeleteAll finished!\n\n");
    
    printf("-------------------------------------\n\n");
    
    return EXIT_SUCCESS;
}