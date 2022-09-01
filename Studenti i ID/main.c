#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int main()
{
    Student head = {.name = {0}, .surname = {0}, .id = 0, .next = NULL};
    
    Read("file.txt", &head);
    
    Print(&head);
    
    RemoveByName(&head);
    
    Print(&head);
    
    Student head2 = {.name = {0}, .surname = {0}, .id = 0, .next = NULL};
    
    FindDivisible(&head);
    
    Print(&head);
    
    DeleteAll(&head);
    
    Print(&head);
    
    return EXIT_SUCCESS;
}