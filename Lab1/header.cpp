#include "header.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

/*void writeFile(string path) {
	ofstream outFile;
	outFile.open(path);
	if (!outFile.is_open())
	{
		cout << "Cannot open the file!";
	}
	else
	{
		string stringOfText;
		char keyToFinishTypingText = 19;
		cout << "Enter your strings. To finish entering a string press 'Enter'.\n" <<
			"To finish typing text press combination 'Ctrl + s' (hold 'Ctrl' and press 's')\n";
		getline(cin, stringOfText);
		while (stringOfText[0] != keyToFinishTypingText)
		{
			outFile << stringOfText << '\n';
			getline(cin, stringOfText);
		}
	}
	outFile.close();
}*/
void writeFile(string name) {
	int value;
	ofstream inFile;
	cout << "---------------------------------------------" << endl;
	cout << "Type 1 if you want to write a new file." << endl;
	cout << "Type 2 if you want to expand the file." << endl;
	cout << "---------------------------------------------" << endl;
	cin >> value;
	cin.ignore();
	if (value == 1)
		 inFile.open(name);
    else if (value == 2) 
		 inFile.open(name, ios::app);

    if (!inFile.is_open()) {
        cout << "Cant open the file!" << endl;
    }
    else {
		string s;
		char key = 7;
		cout << "---------------------------------------------" << endl;
        cout << "Enter the strings. " << "\n" << "Press ENTER to start a new line. " << "\n" << "Press CTRL + G to end the file." << endl;
		cout << "---------------------------------------------" << endl;
        getline(cin, s);
        while (s[0] != key) {
            inFile << s << "\n";
            getline(cin, s);

        }
		cout << endl;
		inFile.close();
    }
}
void outFile(const string name) {
	ifstream outFile(name);
	if (!outFile.is_open()) {
		cout << "Cant open the file!" << endl;
	}
	else 
	{
		string line;
		while (!outFile.eof()) {
			getline(outFile, line);
			cout << line << endl;
		}
		outFile.close();
	}
}
void createThird(string first, string second, string third, int &num) {
	ifstream ffile(first);
	ifstream sfile(second);
	ofstream tfile(third);
	bool hasCopy;
	string line;
	string sline;
	while (!sfile.eof()) {
		hasCopy = false;
		line = "";
		getline(sfile, line);
		ffile.clear();
		ffile.seekg(0);
		while (!ffile.eof()) {
			sline = "";
		    getline(ffile, sline);
			if (line.compare(sline) == 0) {
				hasCopy = true;
				break;
			}
		}
		if (!hasCopy) {
			tfile << line << "\n";
			num++;
		}
	}
	ffile.close();
	sfile.close();
	tfile.close();
}

