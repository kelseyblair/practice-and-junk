//will_it_work.cpp

#include <stdio.h>
#include <iostream>
#include <string>

int will_it_work( int input )
{
	int x, y, k;

	k = input / 100;
	x = 2;
	y = k + 5;

	while( x < 10 )
	{
		x++;
		y = y + 3;
	}

	if( (3*k + 100) > 43 )
	{
		y++;
		x = x / (x - y);
	}

	return x;
}

int main()
{
	int i = -2000;
	std::cout << "result: " << will_it_work(i) << "\n";
}