#include <iostream>
 
using namespace std;

unsigned long long trials;

// Precondition: nQueens() recursive function calls itself every time
// 				 row position incremented while row does not equal to 
//				 n board size in which n represents all possible 
//				 rows/columns on (n x n) chessboard. 
//
// Postcondition: If row is equal to n, It returns true as all possible
//				 queens on nxn chessboard are placed successfully where 
//				 no queen conflicts with each other. Solution is found.
//				 backtracks if no queen can be placed in the current row.

bool nQueens(const int row, int col[], const int n)
{
	bool Valid = false; // this checks to see if a queen can be placed
						
     for(int i = 0; i < n; i++) 
     {	
	 	trials++; // keep track of the number of trials for current queen
     	int k = 0;//index for k position in row
     	col[row] = i; //hold the value position
     	
     	//CHECK SQUARES
     	while (k < row) 
     	{
    	   // if same column or same diagnonals
     	   // solution by "reverse engineering" the answer
     	   if (col[k] == i || col[k] == i - row + k || col[k] == i + row - k)
           break;
     		
     		k++;
     	}
     	
     	//BASE CASES
     	if(k == row)   							    	
     	{
     		//case in which all queens are placed
     		if (row >= n -1) Valid = true;
     			
     		//if still more rows call function again to place another queen
     		else   
				// set bool value Valid to nQueens so it indicates
				// if queen can be placed.		
   	  			Valid = nQueens(row+1, col, n);// call function again 
   		
    		// print when it position is safe 
    		if (Valid) //queen on current row is placed
    		{	
				//printing
    	 	 	for ( int p = 0; p < n; p++ ) 
			 	{		
			  		if (p == i)cout << '*' ;
                    else cout << '.';
              	}
              
              cout << '\n';
              break;
    		}
     	}
     }
     return Valid; 
}



// Precondition: none, just specify the board size.SolveQ() is called in
//				  int main() function
//
// Postcondition: shows the number of trials and where each queen is placed
//				  Calls the nQueens recursive function. 

void solveQ(int boardsize)
{
	bool solution;
	for ( int Q = 1; Q < boardsize + 1 ; Q++ ) 
	{
    	int col[Q];
    	cout << "Queen #" << Q << '\n';
       
       	//apply the queen
        solution = nQueens( 0, col, Q );
        if (!solution) cout << "no solution \n";
      
        cout << "trials: " << trials << "\n\n";
    }
} 
 
int main()
{
	
	int boardsize;
	cout << "enter board size: "; 
	cin >> boardsize;
	
	solveQ (boardsize);
 
        return 0;
}
