#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int CreateNew(NumberP head)
{
    NumberP new = NULL;
    new = (NumberP)malloc(sizeof(Number));
    
    if(!new)
    {
        perror("Coudln't allocate memory!");
        return EXIT_FAILURE;
    }
    
    int n = 0;
    
    n = rand() % 100;
    new->number = n;
    new->next = NULL;
    Insert(head, new);
    
    return EXIT_SUCCESS;
}

int Insert(NumberP head, NumberP new)
{
    if(!head || !new)
    {
        return EXIT_FAILURE;
    }
    
    new->next = head->next;
    head->next = new;
    
    return EXIT_SUCCESS;
}

int Print(NumberP head)
{
    NumberP temp = head;
    
    while(temp->next)
    {
        printf("%d\n", temp->next->number);
        temp = temp->next;
    }
    
    printf("\n------------\n\n");
    
    return EXIT_SUCCESS;
}

int DeleteAfter(NumberP prev)
{
    NumberP temp = NULL;
    
    if(!prev->next)
    {
        return EXIT_SUCCESS;
    }
    
    temp = prev->next;
    prev->next = temp->next;
    free(temp);
    
    return EXIT_SUCCESS;
}

int Remove(NumberP head)
{
    NumberP temp = head;
    
    while(temp->next)
    {
        if(((temp->next->number % 3) == 0) || ((temp->next->number % 10) == 3) || (((temp->next->number / 10) % 10) == 3))
        {
            DeleteAfter(temp);
        }
        else
        {
            temp = temp->next;
        }
    }
    
    return EXIT_SUCCESS;
}

int WriteSorted(NumberP head)
{
    FILE* fp = NULL;
    NumberP temp = NULL;
    NumberP min = NULL;
    NumberP p = NULL;
    
    fp = fopen("file.txt", "w");
    if(!fp)
    {
        perror("Couldn't open file!");
        return EXIT_FAILURE;
    }
    
    while(head->next)
    {
        min = head->next;
        temp = min;
        
        while(temp->next)
        {
            if(temp->next->number < min->number)
            {
                min = temp->next;
            }
            
            temp = temp->next;
        }
        
        fprintf(fp, "%d ", min->number);
        
        p = head;
        while(p->next && p->next->number != min->number)
        {
            p = p->next;
        }
        min = head;
        DeleteAfter(p);
    }
    
    fclose(fp);
    
    return EXIT_SUCCESS;
}
