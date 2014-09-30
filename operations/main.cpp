//  STL stack
/****************************************************
Name: Justine Pham
Date:
Problem Number: Project 7
Instructor: Komogortsev, TSU
Environment and compiler used for compilation, e.g., Linux (eros.cs.txstate)
– g++ or Dev C++ - Windows 7, etc.
*****************************************************/
#include "operations.h"
//#include "stack.cpp"

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

int main()
{

    //initialize the input file...
  	ifstream fin;
	char filename[256];
	
	cout << "Enter file name: ";
	cin >> filename;
  	fin.open(filename);
  	
  	if (!fin)
  		cout << "Error...cannot find file" << endl;

	operations S; // initalized object containing stack

	//while not end of the file... or while the file is good...


        char ch;
        int lines = 0;

       while (fin.get(ch))
        {
            if (ch == '\n')
                lines++;
        }

        cout << lines;
        fin.clear();
        fin.seekg(0, fin.beg);
      

        for (int i = 0; i < lines; i++)
        {


            while (fin.peek() != '\n')
            {
                fin.get(ch); //gets character
                cout << ch;
                S.setChar(ch);  //adds character into the stack
                S.countbrackets(ch); //counts number of brackets to make sure there are a proportional number of them
            }
              S.checkbrackets()	; //checks bracket placement
              S.compareBrackets(); //shows whether or not any brackets are missing or misplaced...
            fin.get(ch);

        }



   return 0;
}
