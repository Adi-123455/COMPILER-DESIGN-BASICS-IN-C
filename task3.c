#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// List of C language keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while", NULL // Sentinel value for end of list
};

// Function to check if a word is a C keyword
int isKeyword(const char *word) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

// Function to check if a character is a valid operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
           ch == '=' || ch == '<' || ch == '>' || ch == '!';
}

// Function to create a file and take code input from user
void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error creating file");
        return;
    }

    char line[1000];
    getchar(); // Clear newline character from buffer after scanf
    printf("Enter code (type 'END' on a new line to finish):\n");

    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "END", 3) == 0)
            break;
        fputs(line, fp); // Write each line to the file
    }

    fclose(fp);
    printf("File '%s' created successfully.\n", filename);
}

// Lexical analysis function to scan the file
void lexicalAnalyze(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char ch, buffer[MAX_LEN];
    int i = 0;

    printf("\n--- Lexical Analysis Output ---\n");

    while ((ch = fgetc(fp)) != EOF) {
        // Check for identifiers or keywords
        if (isalpha(ch) || ch == '_') {
            buffer[i++] = ch;
            while (isalnum(ch = fgetc(fp)) || ch == '_') {
                buffer[i++] = ch;
            }
            buffer[i] = '\0'; // Null-terminate the word
            i = 0;
            ungetc(ch, fp); // Push back non-identifier char

            // Classify the word
            if (isKeyword(buffer))
                printf("Keyword     : %s\n", buffer);
            else
                printf("Identifier  : %s\n", buffer);
        }
        // Skip numbers (basic placeholder)
        else if (isdigit(ch)) {
            while (isdigit(ch = fgetc(fp))) {
                // Skipping over numeric literals
            }
            ungetc(ch, fp); // Return the non-digit character
        }
        // Check and handle operators
        else if (isOperator(ch)) {
            char op[3] = { ch, '\0', '\0' };
            char next = fgetc(fp);

            // Handle compound operators like ==, !=, <=, >=
            if (next == '=' && (ch == '=' || ch == '!' || ch == '<' || ch == '>')) {
                op[1] = next;
            } else {
                ungetc(next, fp); // Return character if not part of compound operator
            }

            printf("Operator    : %s\n", op);
        }
    }

    fclose(fp);
}

// Main function with a user menu
int main() {
    int choice;
    char filename[100];

    do {
        printf("\n--- Lexical Analyzer Menu ---\n");
        printf("1. Create file and enter code\n");
        printf("2. Perform lexical analysis on file\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter filename to analyze: ");
                scanf("%s", filename);
                lexicalAnalyze(filename);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select between 1-3.\n");
        }

    } while (choice != 3);

    return 0;
}
