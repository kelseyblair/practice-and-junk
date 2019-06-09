#include <stdio.h>

typedef union

{

long i;

int k[5];

char c;

} DATE; 

typedef union

{

int k[3];
long i;


char c;




} DATE2; 

struct data{

char cat;

DATE cow;

double dog;

} too; 

DATE max;

int main(int argc, char const *argv[])
{
	printf("long %d\n", sizeof(long));
	printf("int %d\n", sizeof(int));
	printf(" int[5] %d\n", sizeof(int[5]));
	printf("char %d\n", sizeof(char));
	printf("DATE %d\n", sizeof(DATE));
	printf("double %d\n", sizeof(double));

	printf("DATE2 %d\n", sizeof(DATE2));

	printf("struct data %d\n", sizeof(struct data));
	printf(" max %d\n", sizeof(max));
	printf(" struct data + max %d\n",sizeof(struct data)+sizeof(max));

	return 0;
}