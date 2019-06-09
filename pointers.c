// pointers.c
#include <stdio.h>
#include <stdint.h>

/* WHAT DOES IT DO: POINTERS

p++; ---- p increments
++p; ---- p increments
++*p; ---- value at p increments
++(*p); ---- value at p increments
++*(p); ---- value at p increments
*p++; ----
(*p)++; ----
*(p)++; ----
*++p; ---- segfault (pointer increments before you use it)
*(++p); ---- segfault

*/

int main()
{

	uint32_t a = 10;
	uint32_t *p_a = &a;

	printf("a is %d. p_a is %d. \n", *p_a, p_a);
	printf("sizeof a is %d. sizeof p_a is %d\n\n", sizeof(a), sizeof(p_a) );

/* --- postfix operators --- */

	// p_a increments
	printf("p_a++\n");
	p_a++;
	printf("a is %d. p_a is %d. \n\n", *p_a, p_a); 

	// a increments
	printf("(*p_a)++\n");
	(*p_a)++;
	printf("a is %d. p_a is %d. \n\n", *p_a, p_a);

	//p_a increments
	printf("*p_a++\n");
	*p_a++;
	printf("a is %d. p_a is %d. \n\n", *p_a, p_a);

	// p_a increments
	printf("*(p_a)++\n");
	*(p_a)++;
	printf("a is %d. p_a is %d. \n\n", *p_a, p_a);

/* --- prefix operators --- */
	a = 10;
	*p_a = &a;

	printf("\na is %d. p_a is %d. \n\n", *p_a, p_a);


	// p_a increments
	printf("++p_a\n");
	++p_a;
	printf("a is %d. p_a is %d. \n\n", *p_a, p_a); 

	// a increments
	printf("++(*p_a)\n");
	++(*p_a);
	printf("a is %d. p_a is %d. \n\n", *p_a, p_a);

	//a increments
	printf("++*p_a\n");
	++*p_a;
	printf("a is %d. p_a is %d. \n\n", *p_a, p_a);

	// // segfault
	// printf("++*(p_a)\n");
	// ++*(p_a);
	// printf("a is %d. p_a is %d. \n\n", *p_a, p_a);


	return 0;
}