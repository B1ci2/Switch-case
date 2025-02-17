#include <stdio.h>

#define MAX 100  // Maximum array size

// Function to display a stylish menu header
void printHeader(const char *title) {
    printf("\n=====================================\n");
    printf("   %s\n", title);
    printf("=====================================\n");
}

int main() {
    int arr[MAX], size, choice, subchoice, i, pos, element;

    // Displaying a fancy program title
    printHeader("ARRAY OPERATIONS PROGRAM");

    // Taking initial array input
    printf(">> Enter the number of elements in the array (Max %d): ", MAX);
    scanf("%d", &size);

    if (size > MAX || size < 0) {
        printf("!! Invalid size entered. Exiting program.\n");
        return 1;
    }

    printf(">> Enter %d elements: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        // Main Menu
        printHeader("MAIN MENU");
        printf("[1] Insert Element\n");
        printf("[2] Delete Element\n");
        printf("[3] Display Array\n");
        printf("[4] Exit\n");
        printf("-------------------------------------\n");
        printf(">> Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                if (size >= MAX) {
                    printf("!! Array is full. Cannot insert more elements!\n");
                    break;
                }

                printHeader("INSERT MENU");
                printf("[1] Insert at Beginning\n");
                printf("[2] Insert at End\n");
                printf("[3] Insert at a Specific Position\n");
                printf("-------------------------------------\n");
                printf(">> Enter your choice: ");
                scanf("%d", &subchoice);

                printf(">> Enter element to insert: ");
                scanf("%d", &element);

                if (subchoice == 1) {
                    pos = 1;
                } else if (subchoice == 2) {
                    pos = size + 1;
                } else if (subchoice == 3) {
                    printf(">> Enter position (1 to %d): ", size + 1);
                    scanf("%d", &pos);
                } else {
                    printf("!! Invalid choice! Returning to menu...\n");
                    break;
                }

                if (pos < 1 || pos > size + 1) {
                    printf("!! Invalid position! Returning to menu...\n");
                    break;
                }

                // Shifting elements to the right
                for (i = size; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = element;
                size++;

                printf("✔ Element inserted successfully!\n");
                break;

            case 2: // Delete
                if (size == 0) {
                    printf("!! Array is empty. Nothing to delete!\n");
                    break;
                }

                printHeader("DELETE MENU");
                printf("[1] Delete from Beginning\n");
                printf("[2] Delete from End\n");
                printf("[3] Delete from a Specific Position\n");
                printf("-------------------------------------\n");
                printf(">> Enter your choice: ");
                scanf("%d", &subchoice);

                if (subchoice == 1) {
                    pos = 1;
                } else if (subchoice == 2) {
                    pos = size;
                } else if (subchoice == 3) {
                    printf(">> Enter position (1 to %d): ", size);
                    scanf("%d", &pos);
                } else {
                    printf("!! Invalid choice! Returning to menu...\n");
                    break;
                }

                if (pos < 1 || pos > size) {
                    printf("!! Invalid position! Returning to menu...\n");
                    break;
                }

                // Shifting elements to the left
                for (i = pos - 1; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                size--;

                printf("✔ Element deleted successfully!\n");
                break;

            case 3: // Display
                printHeader("CURRENT ARRAY");
                if (size == 0) {
                    printf("!! Array is empty.\n");
                } else {
                    printf("Elements: ");
                    for (i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 4: // Exit
                printHeader("EXITING PROGRAM");
                printf("✔ Thank you for using this program!\n");
                return 0;

            default:
                printf("!! Invalid choice! Please try again.\n");
        }
    }

    return 0;
}