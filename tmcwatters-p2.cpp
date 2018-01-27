/****************************
Timothy McWatters
tmcwatters-p2.cpp
programming in C++ project 2

Write a program that takes 
input on cell phone packages/
units used,and then compares them.
Program will let you know what your 
package costs, if there is a cheaper
option, and how much that option will
save you.
The program will verify valid inputs, 
and allow you to run the program
as many times as you want.
*****************************/

#include <iostream>
using namespace std;

int main () {
   
	char packageEntered = '-'; //what package was entered by user
	char goAgain = '-'; // lets the user choose if they would like to run the program again
	int messageUnitsEntered = 0; // how many units are entered by the user
	double chargesForA = 0.0; // how much does pkg A cost for inputs
	double chargesForB = 0.0; // how much does pkg B cost for inputs
	double chargesForC = 0.0; // how much does pkg C cost for inputs
	
	// sets the notation to 2 digits after decimal place
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	
	do { //allows the progam to run at least one time, and then allows the user to choose to go again.
	   // Enter package, makes sure inputs are valid.
	   cout << "Which package are you shopping for? (enter A, B, C)? ";
	   cin >> packageEntered;
	   // first checks package input
	   if ((packageEntered == 'A') || (packageEntered == 'a') || (packageEntered == 'B') 
	        || (packageEntered == 'b') || (packageEntered == 'C') || (packageEntered == 'c'))
      {  
	      // second checks unit input
		   cout << "How many message units? "; 
	      cin >> messageUnitsEntered;
		      while ((messageUnitsEntered < 1) || (messageUnitsEntered > 672)) {
			      cout << "Enter a number from 1 through 672 for message units." << endl; 
			   	cout << "How many message units? ";
			   	cin >> messageUnitsEntered;
			   }
	   }
	   else {
	      cout << "Enter only A, B, or C." << endl;
	   }
	
	   // Calculate the cost of package A
	   if (messageUnitsEntered < 20) {  
	      chargesForA = 9.95;
	   }
	   else { 
         chargesForA = 9.95 + ((messageUnitsEntered - 20) * .25);
	   }
	   // Calculate the cost of package B
	   if (messageUnitsEntered < 100) {  
	      chargesForB = 19.95;
	   }
	   else { 
         chargesForB = 19.95 + ((messageUnitsEntered - 100) * .1);
	   }
	   // Calculate the cost of package C  
	      chargesForC = 39.95;
	
	   // Tests/compares upgrades, and how much an upgrade would save 
	   // Will also print selected cost and upgrade savings to screen
	   switch (packageEntered)
	   {
	      case 'a':
	      case 'A':
		      cout << "The charges are $" << chargesForA << endl;
		   	if (chargesForB < chargesForA) {
			      cout << "By switching to package B you would save $" << (chargesForA - chargesForB) << endl;
			   }
			   if (chargesForC < chargesForA) {
			      cout << "By switching to package C you would save $" << (chargesForA - chargesForC) << endl;
			   }
		      break;
		   case 'b':
		   case 'B':
		      cout << "The charges are $" << chargesForB << endl;
		   	if (chargesForA < chargesForB) {
		   	   cout << "By switching to package A you would save $" << (chargesForB - chargesForA) << endl;
			   }
			   if (chargesForC < chargesForB) {
			      cout << "By switching to package C you would save $" << (chargesForB - chargesForC) << endl;
			   }
		   	break;
		   case 'c':
	   	case 'C':
		      cout << "The charges are $" << chargesForC << endl;
		   	if (chargesForA < chargesForC) {
	   		   cout << "By switching to package A you would save $" << (chargesForC - chargesForA) << endl;
			   }
		   	if (chargesForB < chargesForC) {
			      cout << "By switching to package B you would save $" << (chargesForC - chargesForB) << endl;
			   }
		   	break;
	   }
		// Feeds the Do while loop, asking for another iteration
		cout << "\nDo you want to go again (y/n)? ";
		cin >> goAgain;
		cout << endl;
	} while ((goAgain == 'y') || (goAgain == 'Y'));
	
	cout << "Thank you for using this program. Goodbye." << endl; // final program output

   return 0;
}
