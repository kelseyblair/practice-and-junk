// maze.c

#include<stdio.h>
#include<stdlib.h>

// find path to m[9][9], starting from m[0][0]
// 0 = path, 1 = wall

	static const int maze[10][10] = { 
	//  0  1  2  3  4  5  6  7  8  9 - col |row
	{   0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // 0
	{	0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // 1
	{	0, 1, 1, 1, 1, 1, 0, 0, 0, 1 }, // 2
	{	0, 0, 0, 0, 0, 0, 0, 1, 0, 1 }, // 3
	{	1, 1, 0, 1, 1, 1, 0, 1, 0, 1 }, // 4
	{	1, 1, 0, 1, 1, 1, 0, 1, 0, 1 }, // 5
	{	1, 1, 0, 1, 1, 1, 0, 1, 0, 1 }, // 6 
	{	1, 1, 0, 1, 1, 1, 0, 1, 0, 1 }, // 7
	{	1, 1, 0, 1, 1, 1, 0, 1, 0, 1 }, // 8
	{	1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }  // 9
	};

// direction of previous move, 0 (right), 1 (down), 2(left), 3(up)
typedef enum {RIGHT, DOWN, LEFT, UP} dir;

int which_dir(int r, int c)
{

	dir new_dir;

	//move down
	if(maze[r][c+1] == 0)
	{
		new_dir = DOWN;
	}

	//move right
	else if(maze[r+1][c] == 0)
	{
		new_dir = RIGHT;
	}

	//move left
	else if(maze[r-1][c] == 0)
	{
		new_dir = LEFT;
	}

	//move up
	else if(maze[r][c-1] == 0)
	{
		new_dir = UP;
	}

	return new_dir;
}

void solve_maze()
{
	int row = 0;
	int column = 0;

	static int row_save = 0;
	static int col_save = 0;
	static dir dir_save;

	dir prev_dir;
	dir next_dir;

	while(1)
	{
		if(row == 9 & column == 9)
		{
			printf("Solution Complete! Exiting\n");
			break;
		}

		//maze junction, save spot in case of dead end
		if(maze[row+1][column] == 0 & maze[row][column+1] == 0)
		{
			row_save = row;
			col_save = column;
			dir_save = prev_dir;
		}

		// dead end
		if(maze[row+1][column] == 1 & maze[row][column+1] == 1)
		{
			row_save = row;
			col_save = column;
		}

		// find direction to move
		next_dir = which_dir(row, column);

		switch(next_dir){

		case RIGHT:
			row++;
			break;

		case DOWN:
			column++;
			break;

		case LEFT:
			row--;
			break;

		case UP:
			column--;
			break;
		}



		printf("[%d][%d]\n", row, column);
	}

}

int main()
{

	solve_maze();

	return 0;
}