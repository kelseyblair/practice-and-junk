#include <stdio.h>
#include <stdbool.h>


//function declarations
void init();
void draw();
void get_input();
void find_win();
void print_board();


//typedefs
typedef enum { TOP_LEFT, TOP_MIDDLE, TOP_RIGHT, 
			   MID_LEFT, MID_MIDDLE, MID_RIGHT, 
			   BOT_LEFT, BOT_MIDDLE, BOT_RIGHT 
			 } moves;

typedef enum { EMPTY, X, O }  space_type;
typedef struct { space_type top_left; space_type top_middle; space_type top_right;
			     space_type mid_left; space_type mid_middle; space_type mid_right;
			     space_type bot_left; space_type bot_middle; space_type bot_right; 

			   } board;


//global variables 
bool is_win = false;
board my_board = { EMPTY };
int turn_number = 1;
int game_board[9] = {0, 0, 0, 
					 0, 0, 0, 
					 0, 0, 0};

/*TO DO:
	-determine which x or o populates the movespace
	-reprint the game board to incorporate player moves
	-implement game loop in main. while(win){}

	later:
	-use pointers and header files and such



	max number of moves total = 9
	min number of moves total for a win (by x, since they go first) to happen = 5



*/

/*---- MAIN ----*/
int main(int argc, char const *argv[])
{

	init();
	//draw();

	//game loop
	while(turn_number < 10 && is_win == false)
	{

		get_input();

		print_board();

		find_win();


		turn_number++;
	}

	// print_board();

	return 0;
}

/*---- INIT ----*/
void init()
{

	printf("%s\n", "Welcome to TicTacToe!");
	printf("%s\n", "x goes first. Enter integers 0-8 to make your move.");

}

/*---- DRAW ----*/
void draw()
{
	printf("|--------------------|\n");
	for(int i=0;i<=2;i++)
	{
		printf("|      |      |      |\n");
		if( i != 2 )
		{
			printf("| - - - - - - - - - -|\n");
		}
		
	}
	printf("|--------------------|\n");
}

void get_input()
{
	int input; 

	if(turn_number % 2 == 0 ) //O's turn
	{
		printf("%s %d %s\n", "Turn number ", turn_number, "O's turn!");
		scanf("%d", &input );
		game_board[input] = 2;
	}
	else //X's turn
	{
		printf("%s %d %s\n", "Turn number ", turn_number, "X's turn!");
		scanf("%d", &input );
		game_board[input] = 1;

	}

	printf("%s %d\n", "Your input was: ", input);

}

/*---- FIND_WIN ----*/
/*	win conditions:
	-a row has all the same symbols
	- a column has all the same symbols
	- bot_left, mid_middle, top_right are the same
	- top_left, mid_middle, bot_right are the same

	draw conditions
	-max number of moves taken AND no one satisfies a win condition
*/
void find_win()
{
//TO DO UPDATE WIN CONDITIONS TO NOT WIN WHEN EMPTY GAME

	// row win check
	if(game_board[0] == game_board[1] && game_board[1] == game_board[2])
	{
		is_win = true;
	}
	if(game_board[3] == game_board[4] && game_board[4] == game_board[5])
	{
		is_win = true;
	}
	if(game_board[6] == game_board[7] && game_board[7] == game_board[8])
	{
		is_win = true;
	}

	// column win check
	if(game_board[0] == game_board[3] && game_board[3] == game_board[6])
	{
		is_win = true;
	}
	if(game_board[1] == game_board[4] && game_board[4] == game_board[7])
	{
		is_win = true;
	}
	if(game_board[2] == game_board[5] && game_board[5] == game_board[8])
	{
		is_win = true;
	}

	//diagonal win
	if(game_board[0] == game_board[4] && game_board[4] == game_board[8])
	{
		is_win = true;
	}
	if(game_board[2] == game_board[4] && game_board[4] == game_board[6])
	{
		is_win = true;
	}
}


/*---- PRINT_BOARD ----*/
/* For debugging */
void print_board()
{

	// ---- use for array version
	for(int i = 0; i < 9; i=i+3)
	{
		printf("%d %d %d\n", game_board[i], game_board[i+1], game_board[i+2]);
	}



	/* ---- use for struct version
	printf("%d %d %d\n", my_board.top_left, my_board.top_middle, my_board.top_right);
	printf("%d %d %d\n", my_board.mid_left, my_board.mid_middle, my_board.mid_right);
	printf("%d %d %d\n", my_board.bot_left, my_board.bot_middle, my_board.bot_right);
	*/
}