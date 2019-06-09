#include <stdio.h>
#include <stdint.h>
// #include <random.h>

int hammingWeight(int num)
{
	int numOnes = 0;

	while(num > 0)
	{
		if( (num & 0x1) == 1 )
		{
			numOnes++;
		}
		num >>= 1;
	}


	return numOnes;
}

int bits(uint32_t num)
{
	int count = 0;

	while(num > 0)
	{
		if((num & 1) == 1)
		{
			count++;
		}
		num >>= 1;
	}

	return count;
}

int bits_builtin(uint32_t num)
{
	return __builtin_popcount(num);
}

int bits_speed(unsigned char num)
{
	static const int look_up_bits[] = {
//  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f 
	0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
	4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
	};

	return look_up_bits[num];

}

int bits_memory(unsigned char num)
{
  // static const unsigned char lookup_nibble[16] =
  // {
  //   0, 1, 1, 2, 1, 2, 2, 3, 
  //   1, 2, 2, 3, 2, 3, 3, 4
  // };


  // return lookup_nibble[byte & 0x0F] + lookup_nibble[byte >> 4];

	return 0;
}

int hammingDistance(int a, int b)
{
	//dist = a xor b

	return a ^ b;
}

int main()
{


	uint32_t num = 0xaaaaaaaa;
	// int	num2 = 0x33;
	int numOnes = bits(num);



	printf( "number of bits in %zu: %d\n", num, numOnes );

	// printf("hamming dist between %d and %d = %d\n", num, num2, hammingDistance(num, num2));

	return 0;
}

