#include <stdio.h>

void sort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1; j++) {
            if(a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

int main() {
    int n;
    printf("Size: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    sort(a, n);
    
    printf("Sorted: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
