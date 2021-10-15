#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "menu.h"
#include "linked_list.h"


int meniu()
{
    struct book *head_bk = malloc(sizeof(struct book)); //declaring the head of the list of the books
    struct author *head_ath = malloc(sizeof(struct author)); //declaring the head of the list of the authors

    head_bk->next = NULL; //creating the NULL list
    head_ath->next = NULL; //creating the NULL list

    int option;

    while (option!=5) // menu
    {
        printf("\n\n1. Add a book.\n");
        printf("2. Find the books of an given author.\n");
        printf("3. Find the authors of an given book.\n");
        printf("4. Print the lists.\n");
        printf("5. Exit.\n");
        printf("\nEnter your option: ");

        scanf("%d", &option);

        if (option == 1)  //if cases for every option
            add_book(head_bk, head_ath);
        else if (option == 2)
            print_list_of_books_co_authored(head_ath);
        else if (option == 3)
            print_authors_of_a_book(head_bk);
        else if (option == 4)
        {
            print_list_books(head_bk);
            print_list_authors(head_ath);
        }

    }
    return 0;
}
