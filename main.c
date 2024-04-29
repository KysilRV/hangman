#include <stdio.h>
#include "morse.h"
#include <time.h>
#include <stdlib.h>

int main() {

    // srand(time(NULL));

    // char secret[16];
    // get_word(secret);

    // hangman(secret);

    char output[150];

    text_to_morse("Hello", output);
    puts(output);

    return 0;
}