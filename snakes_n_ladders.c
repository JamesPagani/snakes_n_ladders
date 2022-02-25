#include <stdlib.h>
#include <stdio.h>
/** snakes_n_ladders - Plays a game of snakes and ladders
 * @num_players: Amount of players.
 */

void snakes_n_ladders(int num_players)
{
	int isDone = 0;
	int die;
	int *players;

	if (num_players <= 0)
	{
		printf("You need at least one player to play this game!");
		return;
	}

	players = calloc(num_players, sizeof(int));

	/* Play the game until someone finishes */
	while(!isDone)
	{
		/* Move all players per turn */
		for (int p = 0; p < num_players; p++)
		{
			die = 1 + rand() / ((RAND_MAX + 1u) / 6);
			printf("Player %d rolled %d\n", p + 1, die);
			players[p] += die;
			printf("Player %d landed on square %d\n", p + 1, players[p]);
			if (players[p] >= 25)
			{
				isDone = 1;
				break;
			}
		}
	}

	free(players);
}

/** main - Entry point
 * Return: 1 on success, any value on failure.
 */
int main()
{
	snakes_n_ladders(2);
	return 1;
}
