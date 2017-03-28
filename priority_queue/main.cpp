/****************************************************
Name: JUSTINE PHAM
Date: 2-13-2013
Problem Number: 2
Instructor: Komogortsev, TSU
*****************************************************/

#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>
#include<iomanip>

using namespace std;

//global constants
const int FIRST = 10;
const int LAST = 12;
const int IDlen = 6;
const int numStudents = 40;
const int MAXSCORES = 6;

//structures?

struct student{
	char firstName[FIRST];
	char lastName[LAST];
	int studentID;
	int testScores[MAXSCORES];
	double testAverage;
	int lowest;
	char letterGrade;
};


// function prototypes
int readInfo(int, student[], ifstream&);
int findLowest(int, student[], ifstream&, int, double);
void calcAverage(int, student[], double, double&);
void findLetterGrade(student[], int);
void output(student[], ofstream&, int );


int main()
{

	char pause;

	//fstream objects

	ifstream fin;
	fin. open("student_input.dat");

 	ofstream fout;
	fout.open("student_results.dat");


	ifstream grades("student_input.dat");


	//variables
	int numStudents = 0;
	char count;
	double countTests;
	int checkValid; // indicates whether or not there is a negative test score
						// if function findLowest returns a 0, terminate loop


	//BEGIN PROCESS!!!...

	//input validation - separate function
	if (grades.fail())
	{
		cout << "ERROR! CANNOT OPEN FILE!";
	}
	//read lines to check number of students in the list
		// count number of '\n' in file
		while (grades.good()) //while there is input that can be read in the file
		{
			 count = grades.get(); //gets a character in each iteration

			if (count =='\n') //searches for '\n's
			numStudents++;

		}

		numStudents += 1; //no '\n' at the end of last line of text so add 1.

		// close input file
		fin.close();

		// reopen input file
		fin.open("student_input.dat");

		//arrays
		student Stud_Info[numStudents];




	// Create Table to output Data...
	cout << "FIRST NAME\t" << "LAST NAME\t" << "STUDENT ID\t" << "AVERAGE" << "  \tLETTER GRADE" << "\r\n";
	cout << "-----------------------------------------------------------------------" << "\r\n";

	fout << "FIRST NAME\t" << "LAST NAME\t" << "STUDENT ID\t" << "AVERAGE" << "  \tLETTER GRADE" << "\r\n";
	fout << "-----------------------------------------------------------------------" << "\r\n";

	for (int i = 0; i < numStudents; i++)
	{
		double average = 0;

		// call function to read in student names and numbers
			countTests = readInfo(i, Stud_Info, fin);

		//call function to find lowest test score
			checkValid = findLowest(i, Stud_Info, fin, numStudents, countTests);

		//	cout << endl << "lowest: " << Stud_Info[i].lowest<< endl;
			if (checkValid == 0) break;

		//call fucntion to calculate average
		 	calcAverage(i, Stud_Info, countTests, average);

		//	cout << endl << "AVERAGE: " << average << endl;
			Stud_Info[i].testAverage = average;


		//call function to determine letter grade
			findLetterGrade(Stud_Info, i);


		//call function to output data
			output(Stud_Info, fout, i);

	}



	//close files
	fin.close();
	fout.close();

		cout << "Press any key to continue...";
		cin >> pause;

	return 0;

}





//-------------READ IN DATA------------------------

int readInfo (int i, student Stud_Info[numStudents], ifstream& fin)
{

		//read in first and last name into cstring
		fin >> Stud_Info[i].firstName >> Stud_Info[i].lastName; ;



		//read in student's ID into cstring
		fin >> Stud_Info[i].studentID;




		int j = 0;
		int c = 0; //counter for how many grades less than 6 tests
		while (j < (MAXSCORES - c) && fin >> Stud_Info[i].testScores[j])
		{			// MAXSCORES decreases every c invalid scores found


			//check if the test score is a negative number
			if (Stud_Info[i].testScores < 0)
			{
				 c++;	//counts number of invalid scores
				cout << "ERROR! PLEASE INPUT VALID TEST SCORE!\n";
				break;

			}


		//	cout << Stud_Info[i].testScores[j] << endl;

			j++;
		}

			if (j < 6 || !Stud_Info[i].testScores )
			{
			cout << "\nERROR! LESS THAN SIX VALID TEST SCORES\n";

			}

		return j; //return how many iterations equal to number of tests student has
}




//-----------------FIND LOWEST SCORE---------------

int findLowest(int i, student Stud_Info[], ifstream& fin, int numStudents, double countTests)
{
		int lowElement;
		int lowest = Stud_Info[i].testScores[0];
		int y;

		y = 1;
	while(y < countTests && Stud_Info[i].testScores[y]) // controls the number of arrays for each student
	{

		if (Stud_Info[i].testScores[y] < 0 )
			{
				cout << "ERROR! ENTER NON NEGATIVE SCORE...TERMINATING PROGRAM\n" ;
				return 0;
			}

		if (Stud_Info[i].testScores[y] < lowest)
		 {
		 	lowest = Stud_Info[i].testScores[y];
			lowElement = y;

		}
		// << endl << "\niterations: " << y << " " << Stud_Info[i].testScores[y] << endl;
		y++;


	}

	Stud_Info[i].lowest = lowest;
	return lowest;
}




//-------------------CALCULATE AVERAGE---------------

void calcAverage(int i, student Stud_Info[], double countTests, double& average)
{
	double total; // total is set to zero for each student
	 total = 0.0;

	for (int x = 0; x < countTests; x++)
	{
		total += Stud_Info[i].testScores[x]; //adds up total before dropping the lowest score
	}

	//drop the lowest score and calculate average
	total -= Stud_Info[i].lowest; // subtracts the lowest score

	countTests -= 1.0; // subtracts the total number of tests


	average = (total / countTests); //calculate the average

}




//---------------DETERMINE LETTER GRADE-----------------

void findLetterGrade(student Stud_Info[], int i)
{

	int grade = Stud_Info[i].testAverage;

		if (grade >= 89.5)
			Stud_Info[i].letterGrade = 'A';

		else if (grade < 89.5 && grade >= 79.5)
			Stud_Info[i].letterGrade = 'B';

		else if (grade < 79.5 && grade >= 69.5)
			Stud_Info[i].letterGrade = 'C';

		else if (grade < 69.5 && grade >= 59.5)
			Stud_Info[i].letterGrade = 'D';

		else if (grade < 59.5)
			Stud_Info[i].letterGrade = 'F';






}



//-------------OUTPUT DATA
void output(student Stud_Info[], ofstream& fout, int i)
{
	cout << Stud_Info[i].firstName << "\t\t"
		<< Stud_Info[i].lastName << "\t\t"
		<< Stud_Info[i].studentID<< "\t\t"
		<< setprecision(3)<< Stud_Info[i].testAverage << "\t\t"
		<< Stud_Info[i].letterGrade << "\r\n";


fout << Stud_Info[i].firstName << "\t\t"
		<< Stud_Info[i].lastName << "\t\t"
		<< Stud_Info[i].studentID<< "\t\t"
		<<setprecision(3)<< Stud_Info[i].testAverage << "\t\t"
		<< Stud_Info[i].letterGrade << "\r\n";
	}




//     /\__/\
//    /`    '\				CATS BE
//  === 0  0 ===              TRIPPIN' WHILE WE WORKING!
//    \  --  /
//   /        \
//  /          \
// |            |
// \ ||     ||  /
//  \( )___( )_/#######o

