#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_LENGTH 50

void sortNames(char names[][MAX_NAME_LENGTH], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap names[j] and names[j + 1]
                char temp[MAX_NAME_LENGTH];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int binarySearch(char names[][MAX_NAME_LENGTH], int n, const char *target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int comparison = strcmp(names[mid], target);

        if (comparison == 0) {
            return mid; // Name found
        }
        if (comparison < 0) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Name not found
}

int main() {
    char names[MAX_SIZE][MAX_NAME_LENGTH];
    int n;

    printf("Enter the number of names (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    getchar(); // Consume the newline character left in the buffer

    if (n > MAX_SIZE) {
        printf("Please enter a number less than or equal to %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        // Remove newline character if present
        names[i][strcspn(names[i], "\n")] = 0;
    }

    // Sort names
    sortNames(names, n);

    printf("Sorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    char target[MAX_NAME_LENGTH];
    printf("Enter a name to search for: ");
    fgets(target, MAX_NAME_LENGTH, stdin);
    target[strcspn(target, "\n")] = 0; // Remove newline character

    // Perform binary search
    int result = binarySearch(names, n, target);
    if (result != -1) {
        printf("Name '%s' found at index %d.\n", target, result);
    } else {
        printf("Name '%s' not found.\n", target);
    }

    return 0;
}
