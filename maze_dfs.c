// maze_dfs.c

/*Depth-First-Search-Kickoff( Maze m )
    Depth-First-Search( m.StartCell )
End procedure

Depth-First-Search( MazeCell c )
    If c is the goal
        Exit
    Else
        Mark c "Visit In Progress"
        Foreach neighbor n of c
            If n "Unvisited"
                Depth-First-Search( n )
        Mark c "Visited"
End procedure
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool maze_sol[10][10];
bool was_here[10][10];	

bool solve_maze(int x, int y)
{
	if(x == 9 & y == 9)
	{
		return true;
	}
	if( (maze[x][y] == 2) | (was_here[x][y]) )
	{
		return false;
	}
	was_here[x][y] = true;

	if(x!=0) // check not on left edge
	{ 
		if(solve_maze(x-1, y)) //recall move left
		{
			maze_sol[x][y] = true;
			return true;
		}
	}
	if(x!=9) // check not on right edge
	{ 
		if(solve_maze(x+1, y)) //move to right and solve
		{
			maze_sol[x][y] = true;
			return true;
		}
	}
	if(y!=0) // check not on top edge
	{ 
		if(solve_maze(x, y-1)) //move up and solve
		{
			maze_sol[x][y] = true;
			return true;
		}
	}
	if(y!=9) // check not on bottom edge
	{ 
		if(solve_maze(x, y+1)) //move down and solve
		{
			maze_sol[x][y] = true;
			return true;
		}
	}

	return false;
}

int main()
{
	for(int row = 0; row < 10; row++)
	{
		for(int col = 0; col < 10; col++)
		{
			maze_sol[row][col] = false;
			was_here[row][col] = false;
		}
	}

	solve_maze(0, 0);

	//print solution
	for(int y = 0; y < 10; y++)
	{
		for(int x = 0; x < 10; x++)
		{
			if(maze_sol[x][y] == true )
			{
				printf("X ");
			}
			else
			{
				printf("o ");
			}
		}

		printf("\n");
	}

	printf("\n");
	//print washere
	for(int y = 0; y < 10; y++)
	{
		for(int x = 0; x < 10; x++)
		{
			if(was_here[x][y] == true )
			{
				printf("X ");
			}
			else
			{
				printf("o ");
			}
		}

		printf("\n");
	}

	return 0;
}
