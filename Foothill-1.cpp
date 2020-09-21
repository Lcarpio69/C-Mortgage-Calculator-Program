/*
* Class: CS2A
* Description: In this assignment we practice creating class, create private
* fields, private and public functions, static functions, constructors,
* overlaoded constructors, accessors and mutators.
* Specifically, we create application for calculating mortgae payments
* given loan amount, annual interest rate and years.
* Due date: November 18th, 2019
* Name: Andre Carpio
* File name: Foothill.cpp
* Assignment #: 8
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Mortgage
{
   // prototype
private:

   double loanAmt;
   double annIntRate;
   int years;

   double moIntRate;
   int numPmts;

   static bool validValue(double number);
public:
   Mortgage();
   Mortgage(double loanAmount, double annualRate, int loanYears);
   static unsigned int NO_OF_MONTHES;
   static unsigned int DEFAULT_VALUE;

   double getLoanAmt();
   void setLoanAmt(double amt);

   double getRate();
   void setRate(double rate);

   int getYears();
   void setYears(int yrs);


   double getMonthly();
   double term();
   double getPayBack();

   double getPmt();


   string toString();
};
// define static constants
unsigned int Mortgage::NO_OF_MONTHES = 12;
unsigned int Mortgage::DEFAULT_VALUE = 0;




// client ---------------------------------------------------------------------
int main()
{
   // main client "driver"
   //Instantiate four or more Mortgage objects, 
   //some of them using the default constructor, some
   //using the constructor that takes parameters.
   Mortgage m[4];
   m[0] = Mortgage();
   m[1] = Mortgage(3000, 0.035, 3);
   m[2] = Mortgage(45000, 0.025, 5);
   m[3] = Mortgage(20000, 0.04, 4);
   //Immediately display all objects.
   for (int i = 0; i < 4; i++)
   {
      cout << "Mortgage " << i + 1 << endl;
      cout << m[i].toString() << endl << endl;
   }

   cout << "Interest rates increased to 1%" << endl << endl;
   for (int i = 0; i < 4; i++)
   {
      //Mutate one or more members of every object.
      m[i].setRate(m[i].getRate() + 0.01);
      //Display all objects a second time
      cout << "Mortgage " << i + 1 << endl;
      cout << m[i].toString() << endl << endl;
   }
   //Do two explicit mutator tests. For each, call a mutator in an 
   //if/else statement which prints one message if the call is 
   //successful and a different message if the call fails
   cout << endl << "Setting $10 000 loan amount to Mortage 4" << endl;
   double amount = 10000;
   m[3].setLoanAmt(amount);

   if (m[3].getLoanAmt() == amount)
   {
      cout << "Success!" << endl;
   }
   else
   {
      cout << "Failure!" << endl;
   }
   //Make two accessor calls to demonstrate that they work.
   cout << "Laon amount of Mortgage 4 is $" << m[3].getLoanAmt() << endl;

   cout << endl << "Setting 10% interest rate to Mortage 2" << endl;
   double rate = 0.1;
   m[1].setRate(rate);

   if (m[1].getRate() == rate)
   {
      cout << "Success!" << endl;
   }
   else
   {
      cout << "Failure!" << endl;
   }
   cout << "Interest rate of Mortgage 2 is " << m[1].getRate() * 100 << "%" << endl;
}

//-------------------------------------------------------------------------------

// Mortgage class methods
// a default constructor that initializes all members to DEFAULT_VALUE
Mortgage::Mortgage()
{
   // constructor defintion
   setLoanAmt(DEFAULT_VALUE);
   setRate(DEFAULT_VALUE);
   setYears(DEFAULT_VALUE);
}
//a constructor that initializes all members according to the passed
//parameters.
//no need to get monthyly rate and numebr of payments, they can be derived from
//received values
Mortgage::Mortgage(double loanAmount, double annualRate, int loanYears) {
   // constructor definition
   setLoanAmt(loanAmount);
   setRate(annualRate);
   setYears(loanYears);
}
// mutators and other class definitions..
//mutators
void Mortgage::setLoanAmt(double amt)
{
   if (validValue(amt))	loanAmt = amt;
   else loanAmt = DEFAULT_VALUE;
}
void Mortgage::setRate(double rate)
{
   if (validValue(rate))	annIntRate = rate;
   else annIntRate = DEFAULT_VALUE;

   moIntRate = annIntRate / NO_OF_MONTHES;

}
void Mortgage::setYears(int yrs)
{
   if (validValue(yrs))	years = yrs;
   else years = DEFAULT_VALUE;

   numPmts = years * NO_OF_MONTHES;
}
//accessors
int Mortgage::getYears()
{
   return years;
}
double Mortgage::getRate()
{
   return annIntRate;
}
double Mortgage::getLoanAmt()
{
   return loanAmt;
}
//other accessors
double Mortgage::getMonthly()
{
   return moIntRate;
}
double Mortgage::term()
{
   return pow(1 + getMonthly(), numPmts);
}
double Mortgage::getPmt()
{
   if ((term() - 1) == 0) return 0;
   return getLoanAmt() * getMonthly() * term() / (term() - 1);
}
double Mortgage::getPayBack()
{
   return numPmts * getPmt();
}


//a helper function that the mutators can use to determine
//whether a value is legal.
//This method returns true if the value is greater than DEFAULT_VALUE.
//It returns false, otherwise
bool Mortgage::validValue(double number)
{
   if (number > DEFAULT_VALUE) return true;
   else return false;
}
//a method that returns a string which contains all the 
//information of the Mortgage object
string Mortgage::toString()
{
   return "Loan amount: $" + to_string(getLoanAmt()) + "\n"
      + "Annual Rate: " + to_string(getRate() * 100) + "%\n"
      + "Years: " + to_string(getYears()) + "\n"
      + "Payment: $" + to_string(getPmt()) + "\n"
      + "Total Payments: $" + to_string(getPayBack());

}

/*
OUTPUT

Mortgage 1
Loan amount: $0.000000
Annual Rate: 0.000000%
Years: 0
Payment: $0.000000
Total Payments: $0.000000

Mortgage 2
Loan amount: $3000.000000
Annual Rate: 3.500000%
Years: 3
Payment: $87.906239
Total Payments: $3164.624611

Mortgage 3
Loan amount: $45000.000000
Annual Rate: 2.500000%
Years: 5
Payment: $798.631272
Total Payments: $47917.876335

Mortgage 4
Loan amount: $20000.000000
Annual Rate: 4.000000%
Years: 4
Payment: $451.581093
Total Payments: $21675.892456

Interest rates increased to 1%

Mortgage 1
Loan amount: $0.000000
Annual Rate: 1.000000%
Years: 0
Payment: $0.000000
Total Payments: $0.000000

Mortgage 2
Loan amount: $3000.000000
Annual Rate: 4.500000%
Years: 3
Payment: $89.240773
Total Payments: $3212.667844

Mortgage 3
Loan amount: $45000.000000
Annual Rate: 3.500000%
Years: 5
Payment: $818.628524
Total Payments: $49117.711420

Mortgage 4
Loan amount: $20000.000000
Annual Rate: 5.000000%
Years: 4
Payment: $460.585871
Total Payments: $22108.121828


Setting $10 000 loan amount to Mortage 4
Success!
Laon amount of Mortgage 4 is $10000

Setting 10% interest rate to Mortage 2
Success!
Interest rate of Mortgage 2 is 10%
Press any key to continue . . .


*/