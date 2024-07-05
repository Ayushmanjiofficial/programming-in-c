#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 1000
#define MAX_STRING_LENGTH 256

typedef struct {
    int id;
    char title[MAX_STRING_LENGTH];
    char author[MAX_STRING_LENGTH];
    char publisher[MAX_STRING_LENGTH];
    char date[MAX_STRING_LENGTH];
    char content[10000];  // simplified content storage
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

Library library = { .count = 0 };


void addBook();
void removeBook();
Book* findBookById(int id);
Book* findBookByName(const char* name);
Book* findBookByAuthor(const char* author);
Book* findBookByPublisher(const char* publisher);
Book* findBookByDate(const char* date);
void editBook();
void saveLibraryToFile(const char* filename);
void loadLibraryFromFile(const char* filename);
void wordLookup(const char* word);
void listBooks();

void trimNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void addBook() {
    if (library.count >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }
    Book book;
    book.id = library.count + 1;
    printf("Enter title: ");
    fgets(book.title, MAX_STRING_LENGTH, stdin);
    trimNewline(book.title);
    printf("Enter author: ");
    fgets(book.author, MAX_STRING_LENGTH, stdin);
    trimNewline(book.author);
    printf("Enter publisher: ");
    fgets(book.publisher, MAX_STRING_LENGTH, stdin);
    trimNewline(book.publisher);
    printf("Enter date: ");
    fgets(book.date, MAX_STRING_LENGTH, stdin);
    trimNewline(book.date);
    printf("Enter content: ");
    fgets(book.content, 10000, stdin);
    trimNewline(book.content);

    library.books[library.count++] = book;
    printf("Book added successfully.\n");
}

void removeBook() {
    int id;
    printf("Enter book ID to remove: ");
    scanf("%d", &id);
    getchar();  // consume newline
    for (int i = 0; i < library.count; i++) {
        if (library.books[i].id == id) {
            for (int j = i; j < library.count - 1; j++) {
                library.books[j] = library.books[j + 1];
            }
            library.count--;
            printf("Book removed successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

Book* findBookById(int id) {
    for (int i = 0; i < library.count; i++) {
        if (library.books[i].id == id) {
            return &library.books[i];
        }
    }
    return NULL;
}

Book* findBookByName(const char* name) {
    for (int i = 0; i < library.count; i++) {
        if (strstr(library.books[i].title, name) != NULL) {
            return &library.books[i];
        }
    }
    return NULL;
}

Book* findBookByAuthor(const char* author) {
    for (int i = 0; i < library.count; i++) {
        if (strstr(library.books[i].author, author) != NULL) {
            return &library.books[i];
        }
    }
    return NULL;
}

Book* findBookByPublisher(const char* publisher) {
    for (int i = 0; i < library.count; i++) {
        if (strstr(library.books[i].publisher, publisher) != NULL) {
            return &library.books[i];
        }
    }
    return NULL;
}

Book* findBookByDate(const char* date) {
    for (int i = 0; i < library.count; i++) {
        if (strstr(library.books[i].date, date) != NULL) {
            return &library.books[i];
        }
    }
    return NULL;
}

void editBook() {
    int id;
    printf("Enter book ID to edit: ");
    scanf("%d", &id);
    getchar();  // consume newline
    Book* book = findBookById(id);
    if (book == NULL) {
        printf("Book not found.\n");
        return;
    }
    printf("Editing book ID %d\n", id);
    printf("Enter new title (current: %s): ", book->title);
    fgets(book->title, MAX_STRING_LENGTH, stdin);
    trimNewline(book->title);
    printf("Enter new author (current: %s): ", book->author);
    fgets(book->author, MAX_STRING_LENGTH, stdin);
    trimNewline(book->author);
    printf("Enter new publisher (current: %s): ", book->publisher);
    fgets(book->publisher, MAX_STRING_LENGTH, stdin);
    trimNewline(book->publisher);
    printf("Enter new date (current: %s): ", book->date);
    fgets(book->date, MAX_STRING_LENGTH, stdin);
    trimNewline(book->date);
    printf("Enter new content (current: %s): ", book->content);
    fgets(book->content, 10000, stdin);
    trimNewline(book->content);

    printf("Book edited successfully.\n");
}

void saveLibraryToFile(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    fwrite(&library, sizeof(Library), 1, file);
    fclose(file);
    printf("Library saved to %s.\n", filename);
}

void loadLibraryFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }
    fread(&library, sizeof(Library), 1, file);
    fclose(file);
    printf("Library loaded from %s.\n", filename);
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void wordLookup(const char* word) {
    char lowerWord[MAX_STRING_LENGTH];
    strncpy(lowerWord, word, MAX_STRING_LENGTH);
    toLowerCase(lowerWord);

    for (int i = 0; i < library.count; i++) {
        char lowerContent[10000];
        strncpy(lowerContent, library.books[i].content, 10000);
        toLowerCase(lowerContent);

        int count = 0;
        char* ptr = strstr(lowerContent, lowerWord);
        while (ptr != NULL) {
            count++;
            ptr = strstr(ptr + 1, lowerWord);
        }
        if (count > 0) {
            printf("Word '%s' found %d times in book ID %d titled '%s'.\n", word, count, library.books[i].id, library.books[i].title);
        }
    }
}

void listBooks() {
    for (int i = 0; i < library.count; i++) {
        printf("ID: %d, Title: %s, Author: %s, Publisher: %s, Date: %s\n",
               library.books[i].id,
               library.books[i].title,
               library.books[i].author,
               library.books[i].publisher,
               library.books[i].date);
    }
}


int main() {
    int choice;
    char filename[MAX_STRING_LENGTH];
    char word[MAX_STRING_LENGTH];

    while (1) {
        printf("Library Menu:\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Look up Book by ID\n");
        printf("4. Look up Book by Name\n");
        printf("5. Look up Book by Author\n");
        printf("6. Look up Book by Publisher\n");
        printf("7. Look up Book by Date\n");
        printf("8. Edit Book\n");
        printf("9. Save Library\n");
        printf("10. Load Library\n");
        printf("11. Word Lookup\n");
        printf("12. List Books\n");
        printf("13. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3: {
                printf("Enter book ID: ");
                int id;
                scanf("%d", &id);
                getchar();  // consume newline
                Book* book = findBookById(id);
                if (book) {
                    printf("ID: %d, Title: %s, Author: %s, Publisher: %s, Date: %s\n",
                           book->id, book->title, book->author, book->publisher, book->date);
                } else {
                    printf("Book not found.\n");
                }
                break;
            }
            case 4: {
                printf("Enter book name: ");
                fgets(word, MAX_STRING_LENGTH, stdin);
                trimNewline(word);
                Book* book = findBookByName(word);
                if (book) {
                    printf("ID: %d, Title: %s, Author: %s, Publisher: %s, Date: %s\n",
                           book->id, book->title, book->author, book->publisher, book->date);
                } else {
                    printf("Book not found.\n");
                }
                break;
            }
            case 5: {
                printf("Enter author: ");
                fgets(word, MAX_STRING_LENGTH, stdin);
                trimNewline(word);
                Book* book = findBookByAuthor(word);
                if (book) {
                    printf("ID: %d, Title: %s, Author: %s, Publisher: %s, Date: %s\n",
                           book->id, book->title, book->author, book->publisher, book->date);
                } else {
                    printf("Book not found.\n");
                }
                break;
            }
            case 6: {
                printf("Enter publisher: ");
                fgets(word, MAX_STRING_LENGTH, stdin);
                trimNewline(word);
                Book* book = findBookByPublisher(word);
                if (book) {
                    printf("ID: %d, Title: %s, Author: %s, Publisher: %s, Date: %s\n",
                           book->id, book->title, book->author, book->publisher, book->date);
                } else {
                    printf("Book not found.\n");
                }
                break;
            }
            case 7: {
                printf("Enter date: ");
                fgets(word, MAX_STRING_LENGTH, stdin);
                trimNewline(word);
                Book* book = findBookByDate(word);
                if (book) {
                    printf("ID: %d, Title: %s, Author: %s, Publisher: %s, Date: %s\n",
                           book->id, book->title, book->author, book->publisher, book->date);
                } else {
                    printf("Book not found.\n");
                }
                break;
            }
            case 8:
                editBook();
                break;
            case 9:
                printf("Enter filename to save to: ");
                fgets(filename, MAX_STRING_LENGTH, stdin);
                trimNewline(filename);
                saveLibraryToFile(filename);
                break;
            case 10:
                printf("Enter filename to load from: ");
                fgets(filename, MAX_STRING_LENGTH, stdin);
                trimNewline(filename);
                loadLibraryFromFile(filename);
                break;
            case 11:
                printf("Enter word to look up: ");
                fgets(word, MAX_STRING_LENGTH, stdin);
                trimNewline(word);
                wordLookup(word);
                break;
            case 12:
                listBooks();
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
