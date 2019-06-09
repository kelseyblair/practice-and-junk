// binary_search_array.c

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main()
{
	int arr[SIZE] = {0, 1, 4, 6, 9, 10, 39, 58, 111, 112};

	// binary search, 
	int l, r, t, m;
	l = 0;
	r = SIZE - 1;

	t = 110;


	while(l <= r)
	{
		m = (l+r)/2;

		if(t == arr[m])
		{
			printf("Search successful.\n");
			break;
		}


		if(arr[m] < t)
		{
			l = m+1;

		}
		else if(arr[m] > t)
		{
			r = m-1;
		}
		
	}	


	if(l > r){
		printf("Value not found in array.\n");
		m = -1;
	}

	printf("Index of %d is %d\n", t, m);





	return 0;
}