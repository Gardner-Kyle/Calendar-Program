/********************************************************
* Program:
*    Project 07, Calendar
*    Brother Manley, CS124
* Author:
*    Kyle Gardner
* Summary:
*    Prompt user for offset and number of days in a month then display a
*    calendar using that information.
*
*    Estimated:  3.0 hrs
*    Actual:     4.0 hrs
*      The hardest part was getting the correct relationship between leap year
*      and offset.
**********************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/*********************************************************
 *    Prompt user for a month number and return to main.
 *********************************************************/
int getMonth(int month)
{
   cout << "Enter a month number: ";
   cin >> month;

   while (month > 12 || month < 1)
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> month;
   }

   return month;
}

/*********************************************************
 *    Prompt user for a year number and return to main.
 *********************************************************/
int getYear(int year)
{
   cout << "Enter year: ";
   cin >> year;
   while (year < 1753)
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> year;
   }

   return year;
}

/*********************************************************
 *    Compute whether of not the chosen year is a leap year.
 *********************************************************/
bool isLeapYear(int year)
{
   bool leapYear;

   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
      return true;
   else
      return false;

}

/*********************************************************
 *    Compute the number of days of the month chosen by the user.
 *********************************************************/
int computeNumDaysMonth(int month, int year)
{
   int numDays;

   if (month == 1)
   {
      numDays = 31;
   }

   else if (month == 2)
   {
      if (isLeapYear(year))
         numDays = 29;
      else
         numDays = 28;
   }

   else if (month == 3)
   {
      numDays = 31;
   }

   else if (month == 4)
   {
      numDays = 30;
   }

   else if (month == 5)
   {
      numDays = 31;
   }

   else if (month == 6)
   {
      numDays = 30;
   }

   else if (month == 7)
   {
      numDays = 31;
   }

   else if (month == 8)
   {
      numDays = 31;
   }

   else if (month == 9)
   {
      numDays = 30;
   }

   else if (month == 10)
   {
      numDays = 31;
   }

   else if (month == 11)
   {
      numDays = 30;
   }

   else if (month == 12)
   {
      numDays = 31;
   }

   return numDays;
}

/*********************************************************
 *    Calculate offset using month, year, and leap year functions.
 *********************************************************/
int computeOffset(int month, int year)
{
   int numDaysYear = 0;
   int leap;

   while (year > 1753)
   {
      year--;
      if (isLeapYear(year))
         leap = 366;
      else
         leap = 365;

      numDaysYear += leap;
   }

   int numDaysMonth = 0;

   for (month = month - 1; month > 0; month--)
   {
      numDaysMonth += computeNumDaysMonth(month, year);
   }

   int offset = ((numDaysYear + numDaysMonth) % 7);

   return offset;
}

/*********************************************************
 *    Display specific month name according to user input.
 *********************************************************/
void displayMonth(int month, int year)
{
   cout << endl;

   if (month == 1)
   {
      cout << "January";
   }

   else if (month == 2)
   {
      cout << "February";
   }

   else if (month == 3)
   {
      cout << "March";
   }

   else if (month == 4)
   {
      cout << "April";
   }

   else if (month == 5)
   {
      cout << "May";
   }

   else if (month == 6)
   {
      cout << "June";
   }

   else if (month == 7)
   {
      cout << "July";
   }

   else if (month == 8)
   {
      cout << "August";
   }
   else if (month == 9)
   {
      cout << "September";
   }

   else if (month == 10)
   {
      cout << "October";
   }

   else if (month == 11)
   {
      cout << "November";
   }

   else if (month == 12)
   {
      cout << "December";
   }

   cout << ", ";
   cout << year;
   cout << endl;

}

/*********************************************************
 *    Display a calendar system using offset and numDays prompts.
 *********************************************************/
void displayTable(int numDays, int offset)
{
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   int num = 0;

   for (num = 0; num <= offset; num++)

   {
      cout << setw(offset * 4 + 8);

      if (offset == 6)
         cout << setw(4);
   }

   for (num = 1; num <= numDays; num++)
   {
      cout << num << setw(4);

      if (num == (6 - offset) || num == (6 - offset) + 7 ||
         num == (6 - offset) + 14 || num == (6 - offset) + 21 ||
         num == (6 - offset) + 28 && num != 30 && num != 31)
         cout << endl;
   }

   cout << endl;

   return;
}

/*********************************************************
 *    Call other functions to receive user input, calculate values, and
 *    display calendar.
 *********************************************************/
int main()
{
   cout.setf(ios::fixed);

   int month = getMonth(month);
   int year = getYear(year);
   float numDays = computeNumDaysMonth(month, year);
   float offset = computeOffset(month, year);

   displayMonth(month, year);
   displayTable(numDays, offset);

   return 0;
}




