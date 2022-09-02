#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int Read(char fileName[], StudentP head)
{
    StudentP new = NULL;
    FILE* fp = NULL;
    char name[MAX] = {0};
    char surname[MAX] = {0};
    
    fp = fopen(fileName, "r");
    if(!fp)
    {
        perror("Couldn't open file!");
        return EXIT_FAILURE;
    }
    
    while(!feof(fp))
    {
        fscanf(fp, "%s %s\n", name, surname);
        new = CreateNewElement(name, surname);
        if(new)
        {
            Insert(head, new);
        }
    }
    
    fclose(fp);
}

StudentP CreateNewElement(char name[], char surname[])
{
    StudentP new = NULL;
    new = (StudentP)malloc(sizeof(Student));
    if(!new)
    {
        perror("Couldn't allocate memory!");
        return NULL;
    }
    
    int id = 0;
    id = rand() % 100 + 100;
    
    strcpy(new->name, name);
    strcpy(new->surname, surname);
    new->id = id;
    new->next = NULL;
    
    return new;
}

int Insert(StudentP head, StudentP new)
{
    StudentP temp = NULL;
    temp = head;
    int id = new->id;
    
    while(temp->next && temp->next->id < new->id)
    {
        temp = temp->next;
    }
    
    InsertAfter(temp, new);
    
    return EXIT_SUCCESS;
}

int InsertAfter(StudentP prev, StudentP new)
{
    if(!prev || !new)
    {
        return EXIT_FAILURE;
    }
    
    new->next = prev->next;
    prev->next = new;
    
    return EXIT_SUCCESS;
}

int Print(StudentP head)
{
    StudentP temp = NULL;
    temp = head;
    
    printf("\n");
    
    while(temp->next)
    {
        printf("%s %s %d\n", temp->next->name, temp->next->surname, temp->next->id);
        temp = temp->next;
    }
    
    printf("\n---------------------\n");
}

int DeleteAll(StudentP head)
{
    if(!head->next)
    {
        printf("\nDeleteAll success!");
        return EXIT_SUCCESS;
    }
    
    while(head->next)
    {
        DeleteAfter(head);
    }
    
    printf("\nDeleteAll success!");
    
    return EXIT_SUCCESS;
}

int DeleteAfter(StudentP prev)
{
    StudentP q = NULL;
    
    if(!prev->next)
    {
        return EXIT_SUCCESS;
    }
    
    q = prev->next;
    prev->next = q->next;
    free(q);
    
    return EXIT_SUCCESS;
}

int RemoveByName(StudentP head)
{
    StudentP p = NULL;
    StudentP q = NULL;
    p = head;
    
    char currentName[MAX] = {0};
    
    while(p->next)
    {
        q = p->next;
        strcpy(currentName, q->name);
        while(q->next)
        {
            if(strcmp(q->next->name, currentName) == 0)
            {
                DeleteAfter(q);
            }
            else
            {
                q = q->next;
            }
        }
        
        p = p->next;
    }
    
    return EXIT_SUCCESS;
}

int FindDivisible(StudentP head)
{
    int divider = 1;
    int number = 0;
    int result = 1;
    StudentP temp = NULL;
    StudentP q = NULL;
    StudentP p = NULL;
    StudentP new = NULL;
    char n[MAX] = {0};
    char s[MAX] = {0};
    
    temp = head;
    
    p = head;
    while(p->next)
    {
        p = p->next;
    }
    
    printf("\nEnter divider: ");
    scanf("%d", &divider);
    
    if(divider == 0)
    {
        perror("\nDivision with zero isn't possible!\n");
        return EXIT_FAILURE;
    }
    
    while(temp != p)
    {
        q = temp->next;
        number = q->id;
        result = number % divider;
        if(result == 0)
        {
            strcpy(n, q->name);
            strcpy(s, q->surname);
            new = CopyElement(n, s, number);
            if(new)
            {
                InsertAfter(p, new);
            }
            DeleteAfter(temp);
        }
        else
        {
            temp = temp->next;
        }
    }
    
    return EXIT_SUCCESS;
}

StudentP CopyElement(char name[], char surname[], int id)
{
    StudentP new = NULL;
    new = (StudentP)malloc(sizeof(Student));
    if(!new)
    {
        perror("Couldn't allocate memory!");
        return NULL;
    }
    
    strcpy(new->name, name);
    strcpy(new->surname, surname);
    new->id = id;
    new->next = NULL;
    
    return new;
}
