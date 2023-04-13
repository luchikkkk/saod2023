
#include <iostream>
using namespace std;

void string_copy(char* d, char* s);

int main()
{
	char str[] = "Hello!";
	cout << str << endl;

	cout << "Lenght: " << strlen(str) << ' ' << "Size: " << sizeof(str) << endl;

	char t[32];

	string_copy(t, str);

	cout << "Copy: " << t << endl;

	return 0;
}

void string_copy(char* d, char* s) {
	char *pt = d, *pstr = s;

	while (strlen(d) != strlen(s))	
	{
		*pt++ = *pstr++;
	}
}
