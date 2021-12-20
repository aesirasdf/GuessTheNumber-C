#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>  
int getRandoms(int lower, int upper)
{
	srand(time(0));
    int num = (rand() %
       (upper - lower + 1)) + lower;
    return num;
}
int main (void){
	int x = getRandoms(1, 100);
	int lives = 5;
	int guess;
	int bet;
	bool isCheatOn = false;
	printf("===============RULES===============\n");
	printf("Guess the number within %i tries\n", lives);
	printf("We will tell you if the number is higher or lower than your guess\n");
	printf("Your bet will be multiplied by your remaining lives if you guess the number correctly.\n");
	printf("Goodluck and have fun.\n");
	do{
		printf("Place your bet: $");
		scanf("%d", &bet);
		if(bet < 1){
			printf("Bet must be a positive number.\n");
			if(bet == -666){
				printf("CHEAT ACTIVATED! (Bet is disabled)\n");
				isCheatOn = true;
				bet = 0;
			}
		}
	}while(bet < 1 && !isCheatOn);
	printf("===============GAME===============\n");
	do{
		if(isCheatOn)
			printf("The number is : %i\n", x); //CHEAT for testing purpose
		printf("Prize Pool: $%i", (bet * lives));
		do{
			printf("\nGuess the number 1 - 100 (%i live/s left)\n", lives);
			printf("Enter a number:");
			scanf("%i", &guess);
			if(guess < 1 || guess > 100)
				printf("Your guess is out of range, try again!\n");
		}while(guess < 1 || guess > 100);//ensure that the guess is within range.
		if(guess == x){
			printf("\nYou won $%i.\nCongratulations!!!", (bet * lives));
		}
		else{
			lives = lives-1;
			if(lives < 1){
				printf("You lose.\n");
				printf("The number is %i", x);
			}
			else{
				if(guess > x)
					printf("LOWER!!!\n");
				else
					printf("HIGHER!!!\n");
			}
		}
	}while(lives > 0 && guess != x);
	
	return 0;
}
