#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> // for malloc, free

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
    TOKEN_RPAREN, // Right parenthesis

    /* add keyword about '->' */
    TOKEN_ARROW // Arrow operator
};

// Define a function to tokenize the input string
Token* tokenize(char* input) {
    Token* tokens = malloc(100 * sizeof(Token)); // Allocate memory for tokens
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
                if (i == 0 || (tokens[token_count - 1].type != TOKEN_NUMBER && tokens[token_count - 1].type != TOKEN_RPAREN)) {
                    // This is a minus sign
                    tokens[token_count].type = TOKEN_MINUS;
                    strcpy(tokens[token_count].value, "-");
                    token_count++;
                    break;
                } else if (input[i + 1] == '>') {
                    tokens[token_count].type = TOKEN_ARROW;
                    strcpy(tokens[token_count].value, "->");
                    token_count++;
                    i++; // Skip over the '>' character
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
            default:
                // If the character is not a digit or an operator, it is an invalid character
                printf("Invalid character: %c\n", input[i]);
                return NULL;
        }
        i++; // Move on to the next character
    }

    // Add a null token to the end of the token array to indicate the end of tokens
    tokens[token_count].type = '\0';
    tokens[token_count].value[0] = '\0';

    return tokens;
}

int main() {
    // Input expression
    char input[MAX_TOKEN_LENGTH] = "x->y->z";

    // Tokenize the input expression
    Token* tokens = tokenize(input);

    // Parse the tokens to access the field of a variable using "->" operator
    int i = 0;
    while (tokens[i].type != '\0') {
        // Check if the current token is "->"
        if (tokens[i].type == TOKEN_ARROW && i > 0 && tokens[i+1].type != '\0') {
            // Get the name of the variable
            char var_name[MAX_TOKEN_LENGTH];
            strncpy(var_name, tokens[i-1].value, MAX_TOKEN_LENGTH);

            // Get the name of the field
            char field_name[MAX_TOKEN_LENGTH];
            strncpy(field_name, tokens[i+1].value, MAX_TOKEN_LENGTH);

            // Access the field of the variable
            printf("%s.%s\n", var_name, field_name);

            // Skip the next token
            i += 2;
        } else {
            i++;
        }
    }

    return 0;
}
