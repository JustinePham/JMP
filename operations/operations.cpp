/*   
	operations.cpp uses a stack to push in each character read from 
	a string in the input file. Each bracket is pushed into the stack 
	when reading in the string from the file. Then it check for errors 
	in number of brackets and bracket placement by popping out the stack
	
	preconditions: There must be an input file to read from and operations
	class must be initialized. Each function must be called. 
	
	postconditions: it writes to the input file with either no errors,
	bracket misplacement or missing brackets.
*/
#include "operations.h"

operations::operations()
{
  stack< int, vector<char> > charStack;
    ob =0;
    cb =0;
    OB =0;
    CB =0;

} // constructor

ofstream operations::fout("exp_output.dat", ios::out);

void operations::setChar(char ch)
{
	//push character into stack
	charStack.push(ch);

	//call getChar
	getChar(ch);

}

// returns the character value
char operations::getChar(char ch)
{
	return ch;
}

void operations::countbrackets( char ch)
{
	
	fout << ch;


	if (ch == '(')
		ob++;
	if (ch == ')')
		cb++;

	if (ch == '[')
		OB++;
	if (ch == ']')
		CB++;

// used to count/keep track of/ compare the number of brackets and what kind of brackets...
}

// If brackets are equal or unequal to even number of brackets then 
// check the placement of brackets. Checks for ... 
// 
// 		1. Wrong type of brackets: New set of brackets ')' before '('
// 		2. Uneven number of any brackets. 
// 
void operations::checkbrackets() // this checks for bracket placement...
{

	int RB =0 , LB = 0, rb = 0, lb = 0;
	while (!charStack.empty()) //pop out while stack isn't empty
	{
		if (charStack.top() == ')' && !charStack.empty())
		{	
			while (!charStack.empty())
			{  
				if (charStack.top() == ')') //take into account multiple )
					rb++;
				if (charStack.top() == '[') //misplaced '[' if it comes before '('
                    OB++;
                if (charStack.top() == ']')
                    {
                        CB++;
                        break;
                    }
                if (charStack.top() == '(')
                    lb++;
                if (charStack.empty() || rb == lb)
                {
                    charStack.pop(); // once it has proportional number of (), go to next one...
                    break;
                }
                charStack.pop();
 			}
		}
		else if (charStack.top() == ']')
		{	
			while (charStack.top() != '[' && !charStack.empty()) // while the [] do not close
			{
				//cout << "check while loop until '[' " << endl;
				if (charStack.top () == ']')
				{	//cout << " if ] " << endl;
					RB++; // count the number of big brackets...
				}
				if (charStack.top() == '(')	//incorrect placement if '(' comes before '['
				{	
					ob++; // misplaced bracket..missing ')'
				}
				if (charStack.top() == ')')  // check the brackets within the []
                {
                 //   cb++;
					break;
                }
                charStack.pop();
			}
		}
        else if (charStack.top() == '(' && rb == 0) // if no ) counted before (
        {  
            ob++;
            break;
        }
        else if (charStack.top()=='[' && RB == 0) //if no ] bracket counted before [ bracket
        {
            OB++;
            break;
        }
        else
            charStack.pop();



    }

}


void operations::compareBrackets()
{
	//cout <<"   "<< ob << cb << OB << CB;
	
	
	if ((cb - ob) >= 6)
    {
   		cout << "\t more than six elements";
   		fout << "\t more than six elements";
   	}
   	else if ((ob - cb) >= 6)
    {
   		cout << "\t more than six elements";
   		fout << "\t more than six elements";
   	}	
	else if ((CB - OB) >= 6)
    {
   		cout << "\t more than six elements";
   		fout << "\t more than six elements";
   	}
   	else if ((OB - CB) >= 6)
    {
   		cout << "\t more than six elements";
   		fout << "\t more than six elements";
   	}
	else if ((cb != ob) || (OB != CB))
	{
		cout << "\t === missing ";
		fout << "\t === missing ";
		if (ob > cb)
		{
			cout << ") ";
			fout << ") ";
		}
		if (OB > CB)
		{
			cout << "] ";
			fout << "] ";
		}
		if (cb > ob)
		{
			cout << "( ";
			fout << "( ";
		}
		if (CB > OB)
		{
			cout << "[ ";
			fout << "[ ";
		}

        cout << endl;
        fout << endl;
	}
	else
	{
		cout << "\t valid" << endl;
		fout << "\t valid" << endl;
	}
	//reset the counters...
	ob =0;
	cb=0;
	OB =0;
	CB = 0;
}



operations::~operations()
{

} //deconstructor

