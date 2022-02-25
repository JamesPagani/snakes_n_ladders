# Snakes N Ladders
The classic board game of snakes and ladders, on your CLI (and CPU-controlled only)!

## About this project
Snakes N Ladders is a CLI project in which computers play the classic game of Snakes and Ladders. The user can specify the number of players on the board as well as the position of all snakes and ladders and where they go.

### Quick explaination of the board game
There are `height x length` squares on the board. The goal is to reach the final square at `height x length`. Some of these square can be the bottom of a ladder, which will take you fowards, or the head of a snake, which will return you to a previous square.

## Technical information
- Language: C (Compiled on gcc 9.3.0)
- Developed on: Ubuntu 20 LTS

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
$ ./a.out
```

4. Enjoy.
***
***Jaime Andrés Gálvez Villamarin***
