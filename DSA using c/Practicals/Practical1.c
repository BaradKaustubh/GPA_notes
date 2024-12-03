#include <stdio.h>

#define N 10

int main() {
    int arr[N], n = 0;
    
    printf("Please enter array size (maximum %d): ", N);
    scanf("%d", &n);
    if (n > N) n = N;
    
    printf("Please enter %d integer values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Current array contents: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int choice;
    do {
        printf("\nPlease select an operation:\n");
        printf("1. Add element\n");
        printf("2. Remove last element\n");
        printf("3. Display array\n");
        printf("4. Exit program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (n < N) {
                    int pos;
                    printf("Enter position to insert (1-%d): ", n+1);
                    scanf("%d", &pos);
                    pos--;
                    
                    if (pos < 0 || pos > n) {
                        printf("Error: Invalid position\n");
                    } else {
                        for (int i = n; i > pos; i--) {
                            arr[i] = arr[i-1];
                        }
                        printf("Enter integer to insert: ");
                        scanf("%d", &arr[pos]);
                        n++;
                    }
                } else {
                    printf("Error: Array has reached maximum capacity of %d elements\n", N);
                }
                break;
                
            case 2:
                if (n > 0) {
                    int pos;
                    printf("Enter position to delete (1-%d): ", n);
                    scanf("%d", &pos);
                    pos--;
                    
                    if (pos < 0 || pos >= n) {
                        printf("Error: Invalid position\n");
                    } else {
                        for (int i = pos; i < n-1; i++) {
                            arr[i] = arr[i+1];
                        }
                        n--;
                        printf("Successfully deleted element from position %d\n", pos+1);
                    }
                } else {
                    printf("Error: Cannot delete from empty array\n");
                }
                break;
                
            case 3:
                printf("Current array contents: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
                
            case 4:
                printf("Program terminated successfully\n");
                break;
                
            default:
                printf("Error: Invalid selection. Please choose between 1-4\n");
        }
    } while (choice != 4);
    
    return 0;
}
