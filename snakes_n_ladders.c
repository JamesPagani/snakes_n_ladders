#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**
 * generate_board - Generate a new Snakes and Ladders board
 * @board_size: Size of the board
 * Return: New Board. DO NOT FORGET TO FREE THE MEMORY USED FOR IT!
 */
int *generate_board(int board_size)
{
	int *board;
	/* Making sure we have a value higher than zero */
	if (board_size <= 0)
	{
		printf("The board must have a value higher than 0!");
		exit(90);
	}
	board = calloc(board_size + 1, sizeof(int));

	/* Populating the board with Snakes and Ladders */
	for (int i = 1; i < board_size; i++)
	{
		if (rand() % 2 && board[i] != -1)
		{
			/* Set the destination... */
			board[i] = 1 + rand() / ((RAND_MAX + 1u)/board_size);
			/* Don't let the destination become a snake/ladder */
			board[board[i]] = -1;

			if (board[i] < i)
				printf("Generated a Snake at square %d\n", i);
			else
				printf("Generated stairs at square %d\n", i);
		}
	}
	printf("*-*-*-*-*-*-*-*-*-*\n");
	return board;
}

/** 
 * snakes_n_ladders - Plays a game of snakes and ladders
 * @num_players: Amount of players.
 * @board_size: Size of the board.
 */

void snakes_n_ladders(int num_players, int board_size)
{
	int isDone = 0;
	int die, turn;
	int *positions;
	int *board;

	if (num_players <= 0)
	{
		printf("You need at least one player to play this game!");
		exit(91);
	}
	positions = calloc(num_players, sizeof(int));
	board = generate_board(board_size);

	/* Play the game until someone finishes (isDone == 1) */
	turn = 1;
	while(!isDone)
	{
		printf("----------TURN %d----------\n", turn);
		/* Move all players per turn */
		for (int p = 0; p < num_players; p++)
		{
			/* Roll a die and move the player */
			die = 1 + rand() / ((RAND_MAX + 1u) / 6);
			printf("Player %d rolled %d\n", p + 1, die);
			positions[p] += die;
			printf("Player %d landed on square %d\n", p + 1, positions[p]);

			/* Finish the game if someone wins */
			if (positions[p] >= board_size)
			{
				isDone = 1;
				printf("Player %d won!\n", p + 1);
				break;
			}
			
			/* If this square is a snake/ladder, follow it */
			if (board[positions[p]] > 0)
			{
				if (board[positions[p]] < positions[p])
				{
					printf("Player %d went down a snake, landing on square %d\n", p + 1, board[positions[p]]);
				}
				else
				{
					printf("Player %d went up a ladder, climbing up to square %d\n", p + 1, board[positions[p]]);
				}
				positions[p] = board[positions[p]];
			}
		}
		turn++;
	}

	free(positions);
	free(board);
}

/** 
 * main - Entry point
 * @argc: Amount of arguments
 * @argv: List of arguments (program name included)
 * Return: 1 on success, any value on failure.
 * ARGUMENTS (IN ORDER):
 * - Name of the program
 * - Number of players
 * - Height of the board
 * - Width of the board
 */
int main(int argc, char *argv[])
{
	int num_players, board_size;
	
	if (argc < 4)
	{
		printf("Format: ./%s <PLAYERS> <HEIGHT> <WIDTH>", argv[0]);
		exit(92);
	}
	num_players = atoi(argv[1]);
	board_size = atoi(argv[2]) * atoi(argv[3]);
	srand(time(NULL));
	snakes_n_ladders(num_players, board_size);
	return 1;
}
