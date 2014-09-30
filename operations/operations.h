#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class operations
{
	private:
		int ob, cb, OB, CB; // counters for brackets

	public:
		operations(); // constructor
		~operations(); //deconstructor
		void setChar(char);
		char getChar(char);
		void countbrackets(char);
		void compareBrackets(); //checks to see if there are missing brackets in expression and which kind
		void checkbrackets();
		void checkoperators();

		stack< int, vector<char> > charStack;
		static ofstream fout;

};
#endif
