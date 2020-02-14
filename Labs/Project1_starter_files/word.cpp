#include <stdio.h>

int main() {
    char string[] = "456mph Halftime pizza mon tie peece lol xd Rofl 69696969man lolman69 mkhan825 44verbena lol4noobs ecks dee";
    int stringlen = (sizeof(string)/sizeof(string[0]))-1;
    char words[] = "";
    int wordslen = (sizeof(words)/sizeof(words[0]));
    for ( int i = 0 ; i < stringlen ; i++ ) {
        if ((string[i] >= 'a' && string[i] <= 'z') || 
            (string[i] >= 'A' && string[i] <= 'Z')) {
                //printf("%c\n", string[i]);
                words[wordslen] = string[i];
            } else {
                //printf("This is not a character\n");
            }
    }
    words[wordslen] = '\0';
    printf("%s\n", words);
}