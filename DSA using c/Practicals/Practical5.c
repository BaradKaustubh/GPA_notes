#include <stdio.h>
#include <string.h>

int binary_search(const char *arr[], int n, const char *key) {
    int left = 0;
    int right = n - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], key);
        
        if(cmp == 0)
            return mid;
        else if(cmp > 0) 
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    const char *arr[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    char key[20];
    printf("Enter Element to search: ");
    scanf("%19s", key);
    int result = binary_search(arr, sizeof(arr) / sizeof(arr[0]), key);
    if(result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");
    return 0;
}