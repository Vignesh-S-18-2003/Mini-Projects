#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    int year_published;
    int num_copies;
} Book;

Book books[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Error: maximum number of books reached\n");
        return;
    }

    Book new_book;
    printf("Enter book title: ");
    scanf("%s", new_book.title);
    printf("Enter book author: ");
    scanf("%s", new_book.author);
    printf("Enter year published: ");
    scanf("%d", &new_book.year_published);
    printf("Enter number of copies: ");
    scanf("%d", &new_book.num_copies);

    books[num_books] = new_book;
    num_books++;

    printf("Book added successfully\n");
}

void display_books() {
    if (num_books == 0) {
        printf("No books in library\n");
        return;
    }

    printf("%-50s %-50s %-20s %-20s\n", "Title", "Author", "Year Published", "Number of Copies");
    for (int i = 0; i < num_books; i++) {
        printf("%-50s %-50s %-20d %-20d\n", books[i].title, books[i].author, books[i].year_published, books[i].num_copies);
    }
}

void search_book() {
    if (num_books == 0) {
        printf("No books in library\n");
        return;
    }

    char title[50];
    printf("Enter book title to search: ");
    scanf("%s", title);

    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("%-50s %-50s %-20s %-20s\n", "Title", "Author", "Year Published", "Number of Copies");
            printf("%-50s %-50s %-20d %-20d\n", books[i].title, books[i].author, books[i].year_published, books[i].num_copies);
            return;
        }
    }

    printf("Book not found\n");
}

void menu() {
    printf("Library Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    do {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
