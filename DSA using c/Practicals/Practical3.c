#include <stdio.h>
#include <string.h>

#define MAX_STR 5
#define MAX_LEN 20

void find(char strs[][MAX_LEN], int n, char *key) {
    for(int i = 0; i < n; i++) {
        if(strcmp(strs[i], key) == 0) {
            printf("Found at position %d\n", i + 1);
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    char strs[MAX_STR][MAX_LEN];
    int n;
    
    printf("How many strings?(max 5):- ");
    scanf("%d", &n);
    
    if(n > MAX_STR) {
        n = MAX_STR;
    }
    
    for(int i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", strs[i]);
    }
    
    char key[MAX_LEN];
    printf("Search for: ");
    scanf("%s", key);
    
    find(strs, n, key);
    return 0;
}