#include "header.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string first = "first.txt";
	string second = "second.txt";
	string third = "third.txt";
	int num = 0;
	writeFile(first);
	writeFile(second);
	cout << "First file : " << endl;
	outFile(first);
	cout << "Second file: " << endl;
	outFile(second);
	createThird(first, second, third, num);
	cout << "Third file: " << endl;
	outFile(third);
	cout << "Number of strings: " << num;
	return 0;
}
