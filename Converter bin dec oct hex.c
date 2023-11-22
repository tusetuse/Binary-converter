#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to clear the input buffer
void clear_buffer() {
    int c;
    // Read characters from the input buffer until newline or EOF is encountered
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to check if a binary string is valid
int is_valid_binary(char binary[]) {
    // Iterate through each character in the binary string
    for (int i = 0; i < strlen(binary); i++) {
        // Check if the character is not '0' or '1'
        if (binary[i] != '0' && binary[i] != '1') {
            return 0; // Invalid binary string
        }
    }
    return 1; // Valid binary string
}

// Function to convert a valid binary string to decimal, octal, and hexadecimal
void bin_to_dec_oct_hex(char binary[]) {
    // Check if the binary string is valid
    if (!is_valid_binary(binary)) {
        printf("Invalid binary input. Please try again.");
        return;
    }

    // Convert binary string to decimal using strtol function
    int decimal_number = strtol(binary, NULL, 2);

    // Print the converted decimal, octal, and hexadecimal numbers
    printf("Decimal number: %d \n", decimal_number);
    printf("Octal number: %o\n", decimal_number);
    printf("Hexadecimal number: %x\n", decimal_number);
}

// Function to convert a decimal number to binary, octal, and hexadecimal
void dec_to_bin_oct_hex(int number) {
    printf("Binary number: ");
    int bit_count = sizeof(number) * 8; // Calculate the number of bits in an integer
    int started = 0;

    // Iterate through each bit of the number
    for (int i = bit_count - 1; i >= 0; i--) {
        int bit = (number >> i) & 1; // Extract the i-th bit
        if (bit == 1 || started) {
            started = 1;
            printf("%d", bit);
        }
    }
    if (!started) {
        printf("0");
    }
    printf("\n");

    // Print the octal and hexadecimal representation of the number
    printf("Octal number: %o\n", number);
    printf("Hexadecimal number: %x\n", number);
}

int main() {
    // Print the program header
    printf("Number Converter >>>\n");
    printf("'b' Convert binary to decimal, octal, and hexadecimal ||| 'd' Convert decimal to binary, octal, and hexadecimal ||| 'q' Quit program\n");

    char input[100];
    int choice = 0;

    // Main program loop
    while (choice != 'q') {
        // Prompt user for input
        printf("\nEnter your choice: ");
        fgets(input, sizeof(input), stdin);

        // Use sscanf to extract a character from the input
        if (sscanf(input, "%c", &choice) != 1) {
            printf("Invalid input. Please try again.\n");
            clear_buffer();
            continue;
        }

        // Process user choice
        switch (choice) {
            case 'b':
                // Loop for binary conversion until a valid input is provided
                while (1) {
                    printf("\nEnter a binary number: ");
                    fgets(input, sizeof(input), stdin);
                    input[strcspn(input, "\n")] = '\0'; // Remove newline character

                    // Check if the input is a valid binary string
                    if (is_valid_binary(input)) {
                        bin_to_dec_oct_hex(input);
                        break;
                    } else {
                        printf("Invalid binary input. Please try again.\n");
                    }
                }
                break;
            case 'd':
                int decimal_input;
                printf("\nEnter a decimal number: ");
                
                // Use scanf to read an integer from the input
                if (scanf("%d", &decimal_input) != 1) {
                    printf("Invalid input. Please try again.\n");
                    clear_buffer();
                    continue;
                }
                clear_buffer(); // Clear any remaining characters in the input buffer
                dec_to_bin_oct_hex(decimal_input);
                break;
            case 'q':
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0; // Return from the main function
}