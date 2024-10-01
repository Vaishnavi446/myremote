#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        // Swap characters
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
