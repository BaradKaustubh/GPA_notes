#include <stdio.h>

void bubbleSort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3, 7, 25, 68};
    int size = sizeof(arr)/sizeof(int);
    
    printf("Array before sorting: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    bubbleSort(arr, size);
    
    printf("\nArray after sorting: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
