#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/** 
 * snakes_n_ladders - Plays a game of snakes and ladders
 * @num_players: Amount of players.
 * @board_size: Size of the board.
 */

void snakes_n_ladders(int num_players, int board_size)
{
	int isDone = 0;
	int die;
	int *position;
	int *board;

	if (num_players <= 0)
	{
		printf("You need at least one player to play this game!");
		return;
	}
	if (board_size <= 0)
	{
		printf("Board size has to be bigger than 0!");
		return;
	}
	position = calloc(num_players, sizeof(int));
	board = calloc(board_size + 1, sizeof(int));

	board[3] = 11;
	board[6] = 17;
	board[9] = 18;
	board[10] = 12;
	board[14] = 4;
	board[19] = 8;
	board[22] = 20;
	board[24] = 16;

	/* Play the game until someone finishes */
	srand(time(NULL));
	while(!isDone)
	{
		/* Move all players per turn */
		for (int p = 0; p < num_players; p++)
		{
			die = 1 + rand() / ((RAND_MAX + 1u) / 6);
			printf("Player %d rolled %d\n", p + 1, die);
			position[p] += die;
			printf("Player %d landed on square %d\n", p + 1, position[p]);
			if (position[p] >= board_size)
			{
				isDone = 1;
				printf("Player %d won!\n", p + 1);
				break;
			}
			if (board[position[p]] != 0)
			{
				if (board[position[p]] < position[p])
				{
					printf("Player %d went down a snake, landing on square %d\n", p + 1, board[position[p]]);
				}
				else
				{
					printf("Player %d went up a ladder, climbing up to square %d\n", p + 1, board[position[p]]);
				}
				position[p] = board[position[p]];
			}
		}
	}

	free(position);
	free(board);
}

/** 
 * main - Entry point
 * Return: 1 on success, any value on failure.
 */
int main()
{
	snakes_n_ladders(2, 25);
	return 1;
}
