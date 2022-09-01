#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int main()
{
    Article headA = {.category = {0}, .name = {0}, .amount = 0, .next = NULL};
    Article headR = {.category = {0}, .name = {0}, .amount = 0, .next = NULL};
    
    Read("articles.txt", &headA);
    Read("receipt.txt", &headR);

    RemoveArticlesFromReceipt(&headA, &headR);
    
    Print(&headA);
    
    DeleteAll(&headA);
    DeleteAll(&headR);
    
    Print(&headA);
    
    return EXIT_SUCCESS;
}