#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int Read(char fileName[], StudP head)
{
    FILE* fp = NULL;
    StudP new = NULL;
    char name[MAX] = {0};
    char surname[MAX] = {0};
    
    fp = fopen(fileName, "r");
    if(!fp)
    {
        perror("WARNING!\nCouldn't open file!\n");
        return EXIT_FAILURE;
    }
    
    while(!feof(fp))
    {
        fscanf(fp, "%s %s\n", name, surname);
        new = CreateNew(name, surname);
        if(new)
        {
            Insert(head, new);
        }
    }
    
    fclose(fp);
    
    return EXIT_SUCCESS;
}

StudP CreateNew(char name[], char surname[])
{
    int grade = 0;
    
    StudP new = NULL;
    new = (StudP)malloc(sizeof(Stud));
    if(!new)
    {
        perror("WARNING!\nCouldn't allocate memory!\n");
        return NULL;
    }
    
    grade = rand() % 5 + 1;
    
    strcpy(new->name, name);
    strcpy(new->surname, surname);
    new->grade = grade;
    new->next = NULL;
    
    return new;
}

int Insert(StudP head, StudP new)
{
    StudP temp = head;
    
    while(temp->next && temp->next->grade > new->grade)
    {
        temp = temp->next;
    }
    
    InsertAfter(temp, new);
    
    return EXIT_SUCCESS;
}

int InsertAfter(StudP prev, StudP new)
{
    if(!prev || !new)
    {
        return EXIT_FAILURE;
    }
    
    new->next = prev->next;
    prev->next = new;
    
    return EXIT_SUCCESS;
}

int Print(StudP head)
{
    StudP temp = head;
    
    while(temp->next)
    {
        printf("%s %s %d\n", temp->next->name, temp->next->surname, temp->next->grade);
        temp = temp->next;
    }
    
    printf("\n-------------------\n\n");
    
    return EXIT_SUCCESS;
}

int DeleteAll(StudP head)
{
    if(!head->next)
    {
        printf("DeleteAll finished!\n\n");
        return EXIT_SUCCESS;
    }
    
    while(head->next)
    {
        DeleteAfter(head);
    }
    
    printf("DeleteAll finished!\n");
    
    return EXIT_SUCCESS;
}

int DeleteAfter(StudP prev)
{
    StudP temp = NULL;
    
    if(!prev->next)
    {
        return EXIT_SUCCESS;
    }
    
    temp = prev->next;
    prev->next = temp->next;
    free(temp);
    
    return EXIT_SUCCESS;
}

int DeleteByGrade(StudP head)
{
    StudP temp = head;
    int currentGrade = 0;
    srand(time(0));
    currentGrade = rand() % 5 + 1;
    
    printf("Deleted students with grade: %d\n", currentGrade);
    printf("\n-------------------\n\n");
    
    while(temp->next)
    {
        if(temp->next->grade == currentGrade)
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
