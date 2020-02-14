#include <stdio.h>

void Concatenate (char *a, char *b, char *c) {
    int lena = sizeof(a)/sizeof(a[0]);
    int lenb = sizeof(b)/sizeof(b[0]);
    int lenc = sizeof(c)/sizeof(c[0]);
    for (int i = 0; i < lena ; i ++) {
        c[lenc] = a[i];
    }
    for (int i = 0; i < lenb ; i ++) {
        c[lenc] = b[i]; 
    }
    c[lenc] = '\0';
    printf("%s\n", c);
}
int main () {
    char string1[] = "";
    char string2[] = "";
    char final_string[] = "";
    printf("Print string1:");
    scanf("%s", &string1);
    printf("Print string2:");
    scanf("%s", &string2);
    Concatenate(string1, string2, final_string);
    printf("%s", final_string);
}