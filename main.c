#include <stdio.h>
#include "hangman.h"
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL));

    char secret[16];
    get_word(secret);
    printf("%s", secret);

    printf("%d\n", is_word_guessed("secret", "aeiou"));
    printf("%d\n", is_word_guessed("hello", "aeihoul"));

    char result[30];
    get_guessed_word("container", "arpstxgoieyu", result);

    printf("%s\n", result);


    return 0;
}