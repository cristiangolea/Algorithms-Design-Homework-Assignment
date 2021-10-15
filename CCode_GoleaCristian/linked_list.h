#ifndef CODE_LIST_H
#define CODE_LIST_H


struct book
{
    char *titlu;
    int nr_authors;
    int *author_list;
    struct book *next;
};

struct author
{
    char *nume;
    char *prenume;
    int nr_books;
    int *books_list;
    struct author *next;
};

void add_book(struct book *head_bk, struct author *head_ath);
void print_list_books(struct book *head_bk);
void author_search(struct author *head_ath, char nume[], char prenume[]);
void add_author(struct author *head_ath, char nume1[], char prenume1[]);
void print_list_authors(struct author *head_ath);
void print_list_of_books_co_authored (struct author *head_ath);
void print_authors_of_a_book (struct book *head_bk);
#endif //CODE_LIST_H
