# Snakes N Ladders
The classic board game of snakes and ladders, on your CLI (and CPU-controlled only)!

## About this project
This is a CPU-played recreation of the "Snakes and Ladders" board game, in which the players must reach the last square of the board while climbing ladders and sliding down through snakes. To randomize the board and the movement of the players, a pseudo-random generator is used to populate the board and to roll the die.

## How 2 Run

1. Pull this project with `git pull`.
```
$ git pull git@github.com:JamesPagani/snakes_n_ladders.git
```

2. Compile with `gcc`.
```
# Use the -o Flag if you want the binary to have another name
# If the -o Flag is not used, the output file will be 'a.out'
$ gcc snakes_n_ladders.c -o snakes_n_ladders
```

3. Run the program.
```
# Assuming default name...
$ ./a.out 2 5 5
```
The arguments you *need* to pass to the program are:
- Number of players
- Height of the board
- Width of the board

4. Enjoy.
***
***Jaime Andrés Gálvez Villamarin***
