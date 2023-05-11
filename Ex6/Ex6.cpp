#include <iostream>
#include "Str.h"
#include "_str.h"

using namespace std;

int main()
{
	char inputTextUser[30];
	int inputIntUser = 0;
	Str text1 = "I read the letter. Stood up. Sat down. Pondered for a minute. Then reread the letter again.";
	
	cout << "Enter a substring to search for: ";
	cin >> inputTextUser;
	
	cout << "Enter a start index to search for: ";
	cin >> inputIntUser;

	cout << "\nText: " << text1 << endl;
	cout << "Start index: " << text1.find(inputTextUser, inputIntUser) << endl;
}
