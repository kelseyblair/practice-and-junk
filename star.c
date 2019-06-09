// clock frequency generator
#include <stdio.h>

int main() {

	int clockFreq = 25000000; //25MHz
	int baud = 115200;
	int baudGenAccWidth = 16 ;
	int baudGeneratorInc = 0;
		baudGeneratorInc = (Baud<<BaudGeneratorAccWidth)/clockFreq;
	int BaudGeneratorAcc = 0;


	while(1) // repeat forever
	{
		 BaudGeneratorAcc = BaudGeneratorAcc + BaudGeneratorInc;
	}

	return 0;
}