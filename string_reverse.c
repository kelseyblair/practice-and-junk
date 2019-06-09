#include <stdio.h>
#include <string.h>

/*
*	Pointer practice
*/

/* Print a string char by char with a space between (using pointers) */
void iterate_pointer_through_string(char *pnt2str){
	int count = strlen(pnt2str);
	for(int i = 0; i < count; i++){ /* If I put strlen(pnt2str) where count is, it only counts to 13, not 27. why? */
		printf("%c", *(pnt2str)++);
	}
	printf("\n");
}


/* Print a string in reverse (using pointers), without a temp  */
void string_reverse(char *pnt2str){
	int count = strlen(pnt2str);
	// if count == 0 return
	/* bring a pointer to the end of the string*/
	while(*pnt2str){
		pnt2str++;
	}
	pnt2str--;

	/* print each char from end to start  */
	for(int i = 0; i < count; i++){
		printf("%c", *(pnt2str)--); 
	}
	printf("\n");
}

// incomplete
void string_reverse_temp(char *pnt2str)
{
	char string_to_reverse[strlen(pnt2str)];

	int j = 0;
	for(int i = strlen(pnt2str); i > 0; i--)
	{
		string_to_reverse[j++] = pnt2str[i];
	}

	iterate_pointer_through_string(string_to_reverse);

}

int main(){
	char string_to_reverse[] = "hello berlin, I am a string";

	iterate_pointer_through_string(string_to_reverse); 

	string_reverse(string_to_reverse);

	string_reverse_temp(string_to_reverse); //todo

	printf("done\n");

	return 0;
}