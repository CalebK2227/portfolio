/**
 * @file rock-spock.c
 * 
 * @brief Play Rock-paper-scissors-lizard-Spock against the machine
 * 
 * @details Generates a random choice of move for the computer and takes
 * the user input and translates it into their move choice. Then, the
 * program determines who wins based on the rules of rock spock and
 * prints out who the winner of the game is and how. Note- player wins
 * all ties.
 * 
 * @author Caleb Krcil
 * 
 * @date 9/14/2021
 * 
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define COMPUTER 8088
#define PLAYER 1000

#define CHOICES 5

#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'
#define LIZARD 'L'
#define SPOCK 'V'

void move(int who, int move);
int winner(int computer, int player);
void print_winner(int winner, int comp_move, int player_move);
int nrand(int range);
void seed();

/**
 * Main funcion
 * Prints out the user interface and takes user input for their move.
 * Then generates a random move for the computer.
 * @param computer the computers move
 * @param player the players move
 * @param tmp player input
 * @param i helps determine wether or not input is valid
 * @return zero
 */
int main(void)
{
	int computer;
	int player;
	int i = 1;
        int tmp;

	/* set up the seed value for the random number generator */
	/* call only once */
	seed();

        /* todo - add a while loop to keep playing */
	while(1){
		while(i == 1) {
			printf("Enter a move:\n");
			printf("R for ROCK\n");
			printf("P for PAPER\n");
			printf("S for SCISSORS\n");
			printf("L for LIZARD\n");
			printf("V for SPOCK\n");
			printf("Q to have SPOCK eat a ROCK while chasing a LIZARD and quit\n");
			printf("Move: ");
			while ((tmp = getchar()) != '\n')
						player = tmp;
			if(player == 'Q') {
				printf("Thanks for playing!\nBye!\n");
				exit(0);
			}
			if(player == 'R' || player == 'P' || player == 'S' || player == 'L' || 
			player == 'V'){
				i = 0;
			} 
			else {
				printf("Error, please enter a valid move, (R,P,S,L,V,Q)\n");
		}
	}
        /* todo - error check input */
	/* todo -- exit from program when player selects 5 */
	/* otherwise play a game of rock-paper-scissors-lizard-spock */

        /* debug -- you don't need move() to play game  */
	move(PLAYER, player);

        /* generate random number for computers play */
        switch(nrand(CHOICES)) {
        case 0:
                computer = ROCK;
                break;
        case 1:
                computer = PAPER;
                break;
        case 2:
                computer = SCISSORS;
                break;
        case 3:
                computer = LIZARD;
                break;
        case 4:
                computer = SPOCK;
                break;
        }

	/*debug -- you don't need this to play the game */
	move(COMPUTER, computer);


        /* todo --implement function winner() */
        /* todo --implement function print_winner() */
	print_winner(winner(computer, player), computer, player);
	i = 1;
	}
	return 0;
}


/** prints the player's or computer's  move to stdin
 * used in debugging
 * I decided to keep the function implemented because I felt that it made
 * the game more understandable when the moves were shown.
 * @param who is it the computer or the player's move?
 * @param move what move did they make
 * @return void
 */
void move(int who, int move)
{
	if (who == COMPUTER)
		printf("Computer's play is ");
	else
		printf("Player's play is ");


	switch(move) {
	case ROCK:
		printf("ROCK\n");
		break;
	case PAPER:
		printf("PAPER\n");
		break;
	case SCISSORS:
		printf("SCISSORS\n");
		break;
	case SPOCK:
		printf("SPOCK\n");
		break;
	case LIZARD:
		printf("LIZARD\n");
		break;
    	}
}


/**
 * determines the winner either COMPUTER or PLAYER
 * @param computer the computer's move
 * @param player the player's move
 * @param result who won the game
 * @return the winner of the game
 */
int winner(int computer, int player)
{
	int result = 0;
	/* todo - determine the winner; use switch statements */
	switch(computer) {
		case PAPER:
		switch(player) {
			case ROCK:
			result = COMPUTER;
			break;
			case PAPER:
			result = PLAYER;
			break;
			case SCISSORS:
			result = PLAYER;
			break;
			case LIZARD:
			result = PLAYER;
			break;
			case SPOCK:
			result = COMPUTER;
			break;
		}
		break;
		case ROCK:
		switch(player) {
			case ROCK:
			result = PLAYER;
			break;
			case PAPER:
			result = PLAYER;
			break;
			case SCISSORS:
			result = COMPUTER;
			break;
			case LIZARD:
			result = COMPUTER;
			break;
			case SPOCK:
			result = PLAYER;
			break;
		}
		break;
		case SCISSORS:
		switch(player) {
			case ROCK:
			result = PLAYER;
			break;
			case PAPER:
			result = COMPUTER;
			break;
			case SCISSORS:
			result = PLAYER;
			break;
			case LIZARD:
			result = COMPUTER;
			break;
			case SPOCK:
			result = PLAYER;
			break;
		}
		break;
		case LIZARD:
		switch(player) {
			case ROCK:
			result = PLAYER;
			break;
			case PAPER:
			result = COMPUTER;
			break;
			case SCISSORS:
			result = PLAYER;
			break;
			case LIZARD:
			result = PLAYER;
			break;
			case SPOCK:
			result = COMPUTER;
			break;
		}
		break;
		case SPOCK:
		switch(player) {
			case ROCK:
			result = COMPUTER;
			break;
			case PAPER:
			result = PLAYER;
			break;
			case SCISSORS:
			result = COMPUTER;
			break;
			case LIZARD:
			result = PLAYER;
			break;
			case SPOCK:
			result = PLAYER;
			break;
		}
	break;
	}

	return result;
}

/**
 * prints the winner of the game to stdin
 * @param winner who won the computer or player
 * @param comp_move what move did the computer make
 * @param play_move what move did the player make
 * @return void
 */
void print_winner(int winner, int comp_move, int player_move)
{
	switch(winner) {
		case PLAYER:
		printf("Player Wins!\n");
		break;
		case COMPUTER:
		printf("Computer Wins!\n");
		break;
	}
		switch(comp_move) {
		case PAPER:
		switch(player_move) {
			case ROCK:
			printf("Paper covers rock\n");
			break;
			case PAPER:
			printf("Player wins ties!\n");
			break;
			case SCISSORS:
			printf("Scissors cuts paper\n");
			break;
			case LIZARD:
			printf("Lizard eats paper.\n");
			break;
			case SPOCK:
			printf("Paper disproves Spock\n");
			break;
		}
		break;
		case ROCK:
		switch(player_move) {
			case ROCK:
			printf("Player wins ties!\n");
			break;
			case PAPER:
			printf("Paper covers rock.\n");
			break;
			case SCISSORS:
			printf("Rock crushes scissors\n");
			break;
			case LIZARD:
			printf("Rock crushes Lizard\n");
			break;
			case SPOCK:
			printf("Spock vaporizes rock\n");
			break;
		}
		break;
		case SCISSORS:
		switch(player_move) {
			case ROCK:
			printf("Rock crushes scissors\n");
			break;
			case PAPER:
			printf("Scissors cuts paper\n");
			break;
			case SCISSORS:
			printf("Player wins ties!\n");
			break;
			case LIZARD:
			printf("Scissors decapitates Lizard\n");
			break;
			case SPOCK:
			printf("Spock smashes scissors\n");
			break;
		}
		break;
		case LIZARD:
		switch(player_move) {
			case ROCK:
			printf("Rock crushes Lizards\n");
			break;
			case PAPER:
			printf("Lizard eats paper\n");
			break;
			case SCISSORS:
			printf("Scissors decapitates Lizard\n");
			break;
			case LIZARD:
			printf("Player wins ties!\n");
			break;
			case SPOCK:
			printf("Lizard poisons Spock\n");
			break;
		}
		break;
		case SPOCK:
		switch(player_move) {
			case ROCK:
			printf("Spock vaporizes rock\n");
			break;
			case PAPER:
			printf("Paper disproves Spock\n");
			break;
			case SCISSORS:
			printf("Spock smashes scissors\n");
			break;
			case LIZARD:
			printf("Lizard poisons Spock\n");
			break;
			case SPOCK:
			printf("Player wins ties!\n");
			break;
		}
		break;
	
	}
    /* todo - use a switch statement

    print Computer Wins! or Player Wins!

    And how they won. Use the phrases below

    Scissors cuts paper
    Paper covers rock
    Rock crushes lizard
    Lizard poisons Spock
    Spock smashes scissors
    Scissors decapitates lizard
    Lizard eats paper
    Paper disproves Spock
    Spock vaporizes rock
    Rock crushes scissors
*/
}

/**
 * returns a uniform random integer n, between 0 <= n < range
 * @param range defines the range of the random number [0,range)
 * @return the generated random number
 */
int nrand(int range)
{
	return rand() % range;
}

/**
 * call this to seed the random number generator rand()
 * uses a simple seed -- the number of seconds since the epoch
 * call once before using nrand and similar functions that call rand()
 */
void seed(void)
{
  	srand((unsigned int)time(NULL));
}
