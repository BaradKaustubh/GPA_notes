#include <stdio.h>

void search(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            printf("Found at %d\n", i + 1);
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter numbers: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("Enter number to find: ");
    scanf("%d", &target);
    
    search(arr, size, target);
    return 0;
}
