#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"
#include "menu.h"

void add_book(struct book *head_bk, struct author *head_ath) //add an author to the list
{
    char titlu[100], nume1[100], prenume1[100];
    int nr_ath, j;
    struct book *new_book = malloc(sizeof(struct book)); //allocate space for the new book

    printf("\nEnter the book title: ");
    scanf("%s", titlu);

    new_book->titlu = malloc(strlen(titlu) + 1);  //allocate memory for the title
    strcpy(new_book->titlu, titlu);     //copy the new title in the new node

    printf("\nEnter the number of authors of the book: ");
    scanf("%d", &nr_ath);

    new_book->author_list = (int*) malloc(sizeof(struct author)); //allocate memory for the author list form book node, we allocate size of author structure.

    new_book->nr_authors = nr_ath; //the number of author from the node gets the value we inputed

    for(j=1; j<=nr_ath; j++)       //read all the authors
    {
        printf("\nEnter the author name \nFirst Name: ");
        scanf("%s", prenume1);
        printf("Last Name: ");
        scanf("%s", nume1);

        int ok=0;

        struct author *iterator = head_ath; //declare an iterator for searching in the list of authors

        while (iterator->next != NULL && ok!=1) //search until until the list finished or if we find an author
        {
            if (strcmp(prenume1, iterator->next->prenume)==0 && strcmp(nume1, iterator->next->nume)==0) //compare the new name with the one already in the list
            ok=1;
            iterator = iterator->next; //go to the next element
        }

        if (ok==0) //if we didn't find the author
        {
            add_author(head_ath, prenume1, nume1); //add it to the list

            new_book->author_list[j] = head_ath->next; //add the author to the list of author of the new book

            head_ath->next->books_list[head_ath->next->nr_books] = new_book; //add the book to the list of books of the author
        }
        else
        {
            new_book->author_list[j] = iterator; //add the author to the list of author of the new book
            iterator->nr_books++; //increase the number of book that an author written

            iterator->books_list[iterator->nr_books] = new_book; //add the book to the list of books of the author
        }
    }
    new_book->next = head_bk->next; //link the new node to the list
    head_bk->next = new_book;
}

void add_author(struct author *head_bk, char prenume[], char nume[])
{
    struct author *new_author = malloc(sizeof(struct author));

    new_author->prenume = malloc(strlen(prenume) + 1); // allocate memory for the first name of the author
    strcpy(new_author->prenume, prenume); //copy the name in the new author node.

    new_author->nume = malloc(strlen(nume) + 1); // allocate memory for the last name of the author
    strcpy(new_author->nume, nume); //copy the name in the new author node.

    new_author->books_list = (int*)malloc(sizeof(struct book)); //allocate spate for the book list

    new_author->nr_books = 1; // if we found a new author we know that he wrote a book so nr_book became 1
    new_author->next = head_bk->next; // link the new author to the list.
    head_bk->next = new_author;

}

void print_list_books(struct book *head_bk) //print the list of books
{
    struct book *iterator = head_bk; //creating an iterator to search in the book list

    printf("\nList of books: ");
    while (iterator->next != NULL) //while the list hasn't finished
    {
        printf("%s; ", iterator->next->titlu); // printing the title of the book
        iterator = iterator->next; //going to the next element in the list
    }
}

void print_list_authors(struct author *head_ath)  //print the list of authors
{
    struct author *iterator = head_ath; //creating an iterator to search in the author list

    printf("\nList of authors: ");
    while (iterator->next != NULL) //while the list hasn't finished
    {
        printf("%s %s; ", iterator->next->prenume, iterator->next->nume); // printing the name of the author
        iterator = iterator->next; //going to the next element in the list
    }
}

void print_list_of_books_co_authored (struct author *head_ath) //Find the books of an given author
{
    struct author *iterator = head_ath; //creating an iterator to search in the author list
    struct book *current_book; //creating an iterator for using the book structure
    char nume[100], prenume[100];

    printf("\nEnter the name of the author whose written books you want to know: ");
    printf("\nFirst Name: ");
    scanf("%s", prenume);
    printf("Last Name: ");
    scanf("%s", nume);


    while (!(strcmp(prenume, iterator->next->prenume)==0 && strcmp(nume, iterator->next->nume)==0)) //while we do not find the author
    {
        iterator = iterator->next; //go to the next element
    }
    for (int i=1; i<=iterator->next->nr_books; i++)
    {
        current_book=iterator->next->books_list[i]; //we dereference the pointer from the iterator book list to current book
        printf("%s ",current_book->titlu); // print the title

    }
}
void print_authors_of_a_book (struct book *head_bk) // Find the authors of an given book.
{
    struct book *iterator=head_bk; //creating an iterator to search in the book list
    struct author *current_author; //creating an iterator for using the author structure
    char titlu[100];

    printf("Enter the title whose authors you want to know: ");
    scanf ("%s", titlu);

    while (!(strcmp(titlu, iterator->next->titlu)==0)) //while we do not find the title we seek
    {
        iterator=iterator->next; //go to the next element in the list
    }
    for (int i=1; i<=iterator->next->nr_authors; i++)
    {
        current_author=iterator->next->author_list[i]; // dereference the pointer from the iterator author list to current author
        printf("%s %s; ",current_author->prenume, current_author->nume); // print the author name
    }
}
