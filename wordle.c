#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* getWordle() {   
    const char *strings[] = { "plant", "crash", "blimp", "jokes", "frown", "badge", "plant", "clamp", "stuck", "viper", "globe", "snake", "angel", "april", "march", "noble", "swift", "zebra", "tiger", "vegas", "brick", "spice", "charm", "mango", "cobra" };
    srand(time(0));
    int random_index = rand() % (sizeof(strings) / sizeof(strings[0]));
    return strings[random_index];
}

bool isPresent (const char *wordle, char input) {
    for (int i=0; i<5; i++ )
        if(wordle[i]==input) return true;
    return false;
}

bool processChars(char input[], const char *wordle, int len) {
    bool isCorrect = true;
    printf("\n");
    for(int i=0; i<len; i++ ){
        if (wordle[i] == input[i]) {
            printf("[%c] ", wordle[i]);
        }
        else if (isPresent(wordle, input[i])) {
            printf("*%c* ", input[i]); 
            isCorrect = false;
        }
        else {
            printf("!%c! ", input[i]); 
            isCorrect = false;
        }
    }
    return isCorrect;
}

int main() {
    const char *wordle = getWordle();
    char input[5];
    int guesses = 5;

    printf("Welcome to Wordle by nav33nb, Guess the word !!!\n");
    printf("*x* means character is part of answer but NOT AT THIS POSITION !!!\n");
    printf("!x! means character is NOT part of answer !!!\n\n");
    // printChars("_____",5,guesses-1);

    printf("[_] [_] [_] [_] [_] ");
    while(guesses) {
        printf("          , %d Guesses remaining : ", guesses--);
        scanf("%5s", input);
        bool isCorrect = processChars(input,wordle,5);
        if(isCorrect) {
            printf("\n\n YOU WIN !!!!\n");
            return 0;
        }
    }

    printf("\n\nYOU LOSE !!! Answer was \"%s\"", wordle);
    printf("\n");
}