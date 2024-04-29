#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "morse.h"

void text_to_morse(const char text[], char output[]) {
        char alphMorse[26][5] = {
        ".-",     // A
        "-...",   // B
        "-.-.",   // C
        "-..",    // D
        ".",      // E
        "..-.",   // F
        "--.",    // G
        "....",   // H
        "..",     // I
        ".---",   // J
        "-.-",    // K
        ".-..",   // L
        "--",     // M
        "-.",     // N
        "---",    // O
        ".--.",   // P
        "--.-",   // Q
        ".-.",    // R
        "...",    // S
        "-",      // T
        "..-",    // U
        "...-",   // V
        ".--",    // W
        "-..-",   // X
        "-.--",   // Y
        "--.."    // Z

        
    };
}