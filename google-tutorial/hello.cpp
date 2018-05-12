// hello.cpp: Maggie Johnson
// Description: a program that prints the immortal saying "hello world"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
	int column_prints = 4, row_prints = 6, spaces = 17, i, j;
	string text = "Hello World!";

	for(i = 0; i < row_prints; i ++) {
		for (j = 0; j < column_prints; j++) {
			cout << setw(spaces) << text;
		}
		cout << endl;
	}
	return 0;
}
