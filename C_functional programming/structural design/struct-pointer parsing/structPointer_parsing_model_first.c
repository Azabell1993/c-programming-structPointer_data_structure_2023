#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Test Get Struct-Pointer value model code
#include "libhello.h"

#define MAX_TOKEN_LENGTH 100

// Define a structure for tokens
typedef struct Token {
    int type; // The type of the token (number, operator, etc.)
    char value[MAX_TOKEN_LENGTH]; // The value of the token
} Token;

// Enumerate the types of tokens
enum {
    TOKEN_NUMBER,   // Number
    TOKEN_PLUS,     // Plus operator
    TOKEN_MINUS,    // Minus operator
    TOKEN_MULTIPLY, // Multiply operator
    TOKEN_DIVIDE,   // Divide operator
    TOKEN_LPAREN,   // Left parenthesis
    TOKEN_RPAREN,   // Right parenthesis
    TOKEN_ARROW,     // Arrow keyword parsing
    TOKEN_STRUCT
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

        int j=1;
        // If the character is an operator, tokenize it as an operator
        switch (input[i]) {
            case '+':
                tokens[token_count].type = TOKEN_PLUS;
                strcpy(tokens[token_count].value, "+");
                token_count++;
                break;
            case '-':
                if (i == 0 || (tokens[token_count].type != TOKEN_NUMBER && tokens[token_count].type != TOKEN_RPAREN)) {
                    // This is a minus sign
                    tokens[token_count].type = TOKEN_MINUS;
                    strcpy(tokens[token_count].value, "-");
                    token_count++;
                    break;
                } else if (input[i + 1] == '>') {
                    tokens[token_count].type = TOKEN_ARROW;
                    strcpy(tokens[token_count].value, "->");
                    token_count++;
                    i+=1; // Skip over the '>' character
                    break;
                } else if (input[i + 1] == ' ') {
                    tokens[token_count].type = TOKEN_MINUS;
                    strcpy(tokens[token_count].value, "-");
                    token_count++;
                    i+=1; // Skip over the '>' character
                    break;
                } else if (input[i + 1] != TOKEN_MINUS && input[i+1] != TOKEN_ARROW) {
                    //tokens[token_count].type = TOKEN_MINUS;
                    strcpy(tokens[token_count].value, "-");
                    token_count++;
                    i+=1; // Skip over the '>' character
                    break;
                }
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
            default :
                tokens[token_count].type = TOKEN_STRUCT;
                strcpy(tokens[token_count].value, "structPointer");
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
    input_without_spaces = (char*)malloc(sizeof(char)*(strlen(input)+1));
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
    // Test Data Container 'input' value : get the keyword '->'
    char input[MAX_TOKEN_LENGTH] = "s21xaaa -> y->z->bb -> bb->we->z->awq -e ";

    Token* tokens = tokenize(input);

    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < return_length(input); i++) {
        // Tokenize numbers and struct pointers as a single token until the "->" operator
        if (tokens[i].type == TOKEN_NUMBER || tokens[i].type == TOKEN_STRUCT) { 
            int j = i + 1;
            while (j < return_length(input) && tokens[j].type != TOKEN_ARROW) {
                if (tokens[j].type == TOKEN_NUMBER || tokens[j].type == TOKEN_STRUCT) {
                    strcat(tokens[i].value, tokens[j].value);
                    // Mark the concatenated tokens as already processed by assigning an empty string to its value
                    strcpy(tokens[j].value, "");
                }
                j++;
            }
        }
        // Print the token information only if the value is not empty
        if (strlen(tokens[i].value) > 0) {
            printf("Token %d: %d (%s)\n", i, tokens[i].type, tokens[i].value);
        }
    }

    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    hellofunc hello = new_hellofunc();

    if((0x0001 & 0x0001) ? "true" : "false") {
        return (hello.hello(&hello, 30));
    } else {
        return (printf("Out of range memory values."));
    }

    // char testStructPointer[MAX_TOKEN_LENGTH] = "-> (hello)";


    return (0);
}