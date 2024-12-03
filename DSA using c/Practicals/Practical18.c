#include <stdio.h>

void reverse(char *s, int l) {
    if(l) printf("%c", s[l-1]), reverse(s, l-1);
}

int main() {
    reverse("Hello", 5);
}
