// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <sys/stat.h>
// #include "hangman.h"


// int get_word(char secret[]){
//     // check if file exists first and is readable
//     FILE *fp = fopen(WORDLIST_FILENAME, "rb");
//     if( fp == NULL ){
//         fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
//         return 1;
//     }

//     // get the filesize first
//     struct stat st;
//     stat(WORDLIST_FILENAME, &st);
//     long int size = st.st_size;

//     do{
//         // generate random number between 0 and filesize
//         long int random = (rand() % size) + 1;
//         // seek to the random position of file
//         fseek(fp, random, SEEK_SET);
//         // get next word in row ;)
//         int result = fscanf(fp, "%*s %20s", secret);
//         if( result != EOF )
//             break;
//     }while(1);

//     fclose(fp);

//     return 0;
// }

// int is_word_guessed(const char secret[], const char letters_guessed[]) {
//     int findFlag = 0;

//     for (int i = 0; i < strlen(secret); i++) {
//         findFlag = 0;
//         for (int j = 0; j < strlen(letters_guessed); j++) {
//             if (secret[i] == letters_guessed[j]) {
//                 findFlag = 1;
//                 break;
//             }
//         }
//         if (findFlag == 0) {
//             return 0;
//         }
//     }

//     return 1;
// }

// void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]) {
//     for (int i = 0; i < strlen(secret); i++) {
//         for (int j = 0; j < strlen(letters_guessed); j++) {
//             if (secret[i] == letters_guessed[j]) {
//                 guessed_word[i] = letters_guessed[j];
//                 break;
//             } else {
//                 guessed_word[i] = '_';
//             }
//         }
//     }
//     guessed_word[strlen(secret)] = '\0';
// }

// void get_available_letters(const char letters_guessed[], char available_letters[]) {
//     char alph[40] = "abcdefghijklmnopqrstuvwxyz";
//     int alphLen = strlen(alph);
//     int findFlag = 0;
//     int alphIndex = 0;

//     for (int i = 0; i < alphLen; i++) {
//         findFlag = 0;
//         for (int j = 0; j < strlen(letters_guessed); j++) {
//             if (alph[i] == letters_guessed[j]) {
//                 findFlag = 1;
//                 break;
//             }
//         }
//         if (findFlag == 0) {
//             available_letters[alphIndex] = alph[i];
//             alphIndex++;
//         }
//         available_letters[alphIndex] = '\0';
//     }
// }

// int find_in_string(const char string[], const char letter) {
//     for (int i = 0; i < strlen(string); i++) {
//         if (string[i] == letter) {
//             return 1;
//         }
//     }
//     return 0;
// }

// void hangman(const char secret[]) {
//     int secretLen = strlen(secret);
//     int attempts = 8;
//     char available_letters[40] = "";
//     char letters_guessed[200] = "";
//     char tmpInput[20];
//     int letters_guessed_index = 0;
//     char guessed_word[40] = "";

//     int find_letter = 0;

//     printf("Welcome to the game, Hangman!\n");
//     printf("I am thinking of a word that is %d letters long.\n", secretLen);
//     printf("------------------------\n");

//     while (attempts > 0) {
//         printf("You have %d guesses left.\n", attempts);
//         get_available_letters(letters_guessed, available_letters);
//         printf("Available letters: %s\n", available_letters);
//         printf("Please guess a letter: ");
//         fgets(tmpInput, 20, stdin);
//         if (strlen(tmpInput) - 1 == 1) {
//             /// is a symbol
//             if (tmpInput[0] >= 97 && tmpInput[0] <= 122) {
//                 if (find_in_string(letters_guessed, tmpInput[0])) {
//                     printf("Oops! You have already quessed that: \n"); 
//                     find_letter = 1;
//                 } else {
//                     letters_guessed[letters_guessed_index] = tmpInput[0];
//                     letters_guessed_index++;
//                 }
//             } else if (tmpInput[0] >= 65 && tmpInput[0] <= 90) {
//                 tmpInput[0] += 32;
//                 if (find_in_string(letters_guessed, tmpInput[0])) {
//                     printf("Oops! You have already quessed that: \n"); 
//                     find_letter = 1;
//                 } else {
//                     letters_guessed[letters_guessed_index] = tmpInput[0];
//                     letters_guessed_index++;
//                 }
//             } else {
//                 printf("Oops! '%c' - is not valid synbol: ", tmpInput[0]);
//             }
//             if (!find_letter) {
//                 if (find_in_string(secret, tmpInput[0])) {
//                     printf("Good guess: ");
//                 } else {
//                     printf("Oops! That letter is not in my world: ");
//                     attempts--;
//                 }
//             }
//             find_letter = 0;
//             get_guessed_word(secret, letters_guessed, guessed_word);
//             for (int i = 0; i < strlen(guessed_word); i++) {
//                 printf("%c ", guessed_word[i]);
//             }
//             printf("\n");

//             if (is_word_guessed(secret, letters_guessed)) {
//                 printf("Congratulations, you won!\n");
//                 break;
//             } else {
//                 printf("Sorry, badguess. The word was %s.\n", secret);
//             }

//         } else {
//             if (is_word_guessed(secret, tmpInput)) {
//                 printf("Congratulations, you won!\n");
//                 break;
//             }    
//         }
 
//         printf("------------------------\n");
//     }

//     if (attempts == 0) {
//         printf("Sorry, you ran out of guesses. The word was undeserved.\n");
//     }
// }