//run length encoding

#include <iostream>
#include <string.h>

using namespace std;

void compress(string str){
	int len = str.length();
	int count = 1;

	for(int i = 0; i < len; i++){
		if(str[i]==str[i+1]){
			count++;
		}
		else{
			cout << str[i] << count; 
			count = 1;
		}
	} 
}

int main(int argc, char const *argv[]){
	string s;

	cout << "Enter string to compress: ";
	cin >> s;

	cout << "The result is "; 
	compress(s);
	cout << endl;

	return 0;
}