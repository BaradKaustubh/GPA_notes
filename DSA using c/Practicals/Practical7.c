#include <stdio.h>
#include <string.h>

void sort(char *arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1; j++) {
            if(strcmp(arr[j], arr[j+1]) > 0) {
                char *t = arr[j];
                arr[j] = arr[j+1]; 
                arr[j+1] = t;
            }
        }
    }
}

int main() {
    char *arr[] = {"banana", "apple", "grape", "cherry", "fig", "date"};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before: ");
    for(int i = 0; i < n; i++)
        printf("%s ", arr[i]);
    
    sort(arr, n);
    
    printf("\nAfter: ");
    for(int i = 0; i < n; i++)
        printf("%s ", arr[i]);
    
    return 0;
}
