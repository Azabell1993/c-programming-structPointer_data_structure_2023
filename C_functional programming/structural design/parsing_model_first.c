#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKEN_LENGTH 100

// Define a structure for tokens
typedef struct Token {
    int type; // The type of the token (number, operator, etc.)
    char value[MAX_TOKEN_LENGTH]; // The value of the token
} Token;

// Enumerate the types of tokens
enum {
    TOKEN_NUMBER, // Number
    TOKEN_PLUS, // Plus operator
    TOKEN_MINUS, // Minus operator
    TOKEN_MULTIPLY, // Multiply operator
    TOKEN_DIVIDE, // Divide operator
    TOKEN_LPAREN, // Left parenthesis
    TOKEN_RPAREN // Right parenthesis
};

// Define a function to tokenize the input string
Token* tokenize(char* input) {
    static Token tokens[100]; // An array to store tokens
    int token_count = 0; // The number of tokens
    int i = 0;

    while (input[i]) {
        // Ignore whitespace
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // If the character is a digit, tokenize it as a number
        if (isdigit(input[i])) {
            char value[MAX_TOKEN_LENGTH] = {0};
            int j = 0;
            while (isdigit(input[i])) {
                value[j++] = input[i++];
            }
            tokens[token_count].type = TOKEN_NUMBER;
            strcpy(tokens[token_count].value, value);
            token_count++;
            continue;
        }

        // If the character is an operator, tokenize it as an operator
        switch (input[i]) {
            case '+':
                tokens[token_count].type = TOKEN_PLUS;
                strcpy(tokens[token_count].value, "+");
                token_count++;
                break;
            case '-':
                tokens[token_count].type = TOKEN_MINUS;
                strcpy(tokens[token_count].value, "-");
                token_count++;
                break;
            case '*':
                tokens[token_count].type = TOKEN_MULTIPLY;
                strcpy(tokens[token_count].value, "*");
                token_count++;
                break;
            case '/':
                tokens[token_count].type = TOKEN_DIVIDE;
                strcpy(tokens[token_count].value, "/");
                token_count++;
                break;
            case '(':
                tokens[token_count].type = TOKEN_LPAREN;
                strcpy(tokens[token_count].value, "(");
                token_count++;
                break;
            case ')':
                tokens[token_count].type = TOKEN_RPAREN;
                strcpy(tokens[token_count].value, ")");
                token_count++;
                break;
        }
        i++; // Move on to the next character
    }

    // Add a null token to the end of the token array to indicate the end of tokens
    tokens[token_count].type = '\0';
    tokens[token_count].value[0] = '\0';

    return tokens;

}

int return_length(char *input) {
    char *input_without_spaces;
    input_without_spaces = (char*)malloc(sizeof(char)*sizeof(input_without_spaces));
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != ' ') {
            input_without_spaces[j] = input[i];
            j++;
        }
    }
    input_without_spaces[j] = '\0';

    return (strlen(input_without_spaces));
}

int main() {
    char input[MAX_TOKEN_LENGTH] = "(3 + 4) * 5 - 6 / 2 - 5 + 6 - 2";
   
    Token* tokens = tokenize(input);
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < return_length(input); i++) {
        printf("Token %d: %d (%s)\n", i, tokens[i].type, tokens[i].value);
    }
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    return (0);
}