#include <stdio.h>


// Define the structure
struct Book {
    char title[50];
    char author[30];
    float price;
};

int main() {
    struct Book x;

    // Book details 
    printf("Book Title: ");
    fgets(x.title, sizeof(x.title), stdin);

    printf("book Author Name: ");
    fgets(x.author, sizeof(x.author), stdin);

    printf("Price of the book: ");
    scanf("%f", &x.price);

    // Save to file
    FILE *fp = fopen("book.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(fp, "%s%s%.2f\n", x.title, x.author, x.price);
    fclose(fp);

    // Read from file
    fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\n--- Details of the book from File ---\n");

    fgets(x.title, sizeof(x.title), fp);
    fgets(x.author, sizeof(x.author), fp);
    fscanf(fp, "%f", &x.price);

    printf("Title : %s", x.title);
    printf("Author: %s", x.author);
    printf("Price : %.2f\n", x.price);

    fclose(fp);
    return 0;
}
    