#include <stdio.h>
void guessNumber(int guess) {
    // TODO: write your code here
    if (guess==555){
        printf("Correct. You guessed it!\n");
    }else if (guess<555) {
        printf("Your guess is to low.\n");
    }else{
        printf("Your guess is to high.\n");
    }
}

int main() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}
