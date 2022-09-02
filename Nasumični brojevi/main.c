#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int main()
{
    Number head = {.number = 0, .next = NULL};
    
    time_t t;
    srand((unsigned)time(&t));
    
    for(int i = 0; i < 30; i++)
    {
        CreateNew(&head);
    }
    
    Print(&head);
    
    Remove(&head);
    
    Print(&head);
    
    WriteSorted(&head);
    
    Print(&head);
    
    return EXIT_SUCCESS;
}
