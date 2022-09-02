/*
Napisati program koji generira 30 slučajnih brojeva u opsegu od 0 do 100 i od generiranih brojeva gradi vezanu listu. Ispisati listu.
Izbaciti iz liste sve one brojeve koji su djeljivi s 3 ili imaju znamenku 3 i rezultantnu listu upisati u datoteku u sortiranom redoslijedu
od najmanjeg do najvećeg broja (sama lista ne smije se sortirati prije upisa u datoteku).
*/
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
