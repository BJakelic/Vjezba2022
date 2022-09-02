#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int main()
{
    Stud head = {.name = {0}, .surname = {0}, .grade = 1, .next = NULL};
    
    time_t t;
    srand((unsigned)time(&t));
    
    Read("students.txt", &head);
    
    Print(&head);
    
    DeleteByGrade(&head);
    
    Print(&head);
    
    DeleteAll(&head);
    
    Print(&head);
    
    return EXIT_SUCCESS;
}
