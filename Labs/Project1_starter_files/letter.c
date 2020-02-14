//check if letter
#include <stdio.h>

int main() {
    char article[] = "aaa bbb cccc def";
    char words[] = "";
    int words_position = 0;
    int encountered_char = 0;
    int encountered = 0;
    int article_len = (sizeof(article)/sizeof(article[0]))-1;
    printf("This is the article_len value: %d\n", article_len);
    for (int i = 0; i < article_len ; i++) {
        if ((article[i] >= 'a' && article[i] <= 'z') || 
            (article[i] >= 'A' && article[i] <= 'Z')) { // If they are letters
            if ( encountered == 0) {
                encountered_char = i;
                encountered = 1;
                printf("%c\n", article[i]);
            }
            if ( (article[i] == " ") && // If there is a space and it is more than a character long add to array
                 (i - encountered_char) > 1) {
                //Add to word array
                for ( int j = 0 ; encountered_char >= 0; encountered_char--, j++) {
                    words[words_position + j] = article[i-encountered_char];
                    words_position++;
                }
            words[words_position + 1] = '\0';
            }
        } else { 
            printf("It is not a character\n");
            encountered = 0;
        }
    }
    printf("%s", words);
}