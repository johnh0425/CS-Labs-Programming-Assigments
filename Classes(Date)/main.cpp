#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here
Date::Date() {
   day = 1;
   month = 1;
   year = 2000;
   monthName = "January";
}
Date::Date(unsigned m, unsigned d, unsigned y) {
   month = m;
   day = d;
   year = y;
   int count = 0;
   if (month > 12) {
      month = 12;
      count = count + 1;
   }
   if (m < 1) {
      month = 1;
      count = count + 1;
   }
   if (daysPerMonth(month, year) < day) {
      day = daysPerMonth(month, year);
      count = count + 1;
   }
   if (day < 1) {
      day = 1;
      count = count + 1;
   }
   if (count > 0) {
      cout << "Invalid date values: Date corrected to ";
      printNumeric();
      cout << "." << endl;
   }
   if (month == 1) {
      monthName = "January";
   }
   else if (month == 2) {
      monthName = "February";
   }
   else if (month == 3) {
      monthName = "March";
   }
   else if (month == 4) {
      monthName = "April";
   }
   else if (month == 5) {
      monthName = "May";
   }
   else if (month == 6) {
      monthName = "June";
   }
   else if (month == 7) {
      monthName = "July";
   }
   else if (month == 8) {
      monthName = "August";
   }
   else if (month == 9) {
      monthName = "September";
   }
   else if (month == 10) {
      monthName = "October";
   }
   else if (month == 11) {
      monthName = "November";
   }
   else if (month == 12) {
      monthName = "December";
   }

}
Date::Date(const string &mn, unsigned d, unsigned y) {
   int count = 0;
   day = d;
   year = y;
   if (mn == "January" || mn == "january") {
      monthName = "January";
      month = 1;
   }
   else if (mn == "February" || mn == "february") {
      monthName = "February";
      month = 2;
   }
   else if (mn == "March" || mn == "march") {
      monthName = "March";
      month = 3;
   }
   else if (mn == "April" || mn == "april") {
      monthName = "April";
      month = 4;
   }
   else if (mn == "May" || mn == "may") {
      monthName = "May";
      month = 5;
   }
   else if (mn == "June" || mn == "june") {
      monthName = "June";
      month = 6;
   }
   else if (mn == "July" || mn == "july") {
      monthName = "July";
      month = 7;
   }
   else if (mn == "August" || mn == "august") {
      monthName = "August";
      month = 8;
   }
   else if (mn == "September" || mn == "september") {
      monthName = "September";
      month = 9;
   }
   else if (mn == "October" || mn == "october") {
      monthName = "October";
      month = 10;
   }
   else if (mn == "November" || mn == "november") {
      monthName = "November";
      month = 11;
   }
   else if (mn == "December" || mn == "december") {
      monthName = "December";
      month = 12;
   }
   else {
      monthName = "January";
      month = 1;
      day = 1;
      year = 2000;
      cout << "Invalid month name: the Date was set to ";
      printNumeric();
      cout << "." << endl;
   }
   if (month > 12) {
      month = 12;
      count = count + 1;
   }
   if (month < 1) {
      month = 1;
      count = count + 1;
   }
   if (daysPerMonth(month, year) < day) {
      day = daysPerMonth(month, year);
      count = count + 1;
   }
   if (day < 1) {
      day = 1;
      count = count + 1;
   }
   if (count > 0) {
      cout << "Invalid date values: Date corrected to ";
      printNumeric();
      cout << "." << endl;
   }
   if (daysPerMonth(month, year) <= day) {
      day = daysPerMonth(month, year);
   }
   if (day < 1) {
      day = 1;
   }
}
void Date::printNumeric() const {
   cout << month << "/" << day << "/" << year;
}
void Date::printAlpha() const {
   cout << monthName << " " << day << ", " << year;
}
bool Date::isLeap(unsigned y) const {
   if (year % 400 == 0) {
      return true;
   }
   else if (year % 100 == 0) {
      return false;
   }
   else if (year % 4 == 0){
      return true;
   }
   return false;
}
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   if (m == 4 || m == 6 ||  m == 9 || m == 11) {
      return 30;
   }
   else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
      return 31;
   }
   else if (m == 2) {
      if (isLeap(y) == true) {
         return 29;
      }
      else {
         return 28;
      }
   }
   return 0;
}
string Date::name(unsigned m) const {
   if (m == 1) {
      return "Janruary";
   }
   else if (m == 2) {
      return "Febuary";
   }
   else if (m == 3) {
      return "March";
   }
   else if (m == 4) {
      return "April";
   }
   else if (m == 5) {
      return "May";
   }
   else if (m == 6) {
      return "June";
   }
   else if (m == 7) {
      return "July";
   }
   else if (m == 8) {
      return "August";
   }
   else if (m == 9) {
      return "September";
   }
   else if (m == 10) {
      return "October";
   }
   else if (m == 11) {
      return "November";
   }
   else if (m == 12) {
      return "December";
   }
   return 0;
}
unsigned Date::number(const string &mn) const {
   if (mn == "January") {
      return 1;
   }
   else if (mn == "Febuary") {
      return 2;
   }
   else if (mn == "March") {
      return 3;
   }
   else if (mn == "April") {
      return 4;
   }
   else if (mn == "May") {
      return 5;
   }
   else if (mn == "June") {
      return 6;
   }
   else if (mn == "July") {
      return 7;
   }
   else if (mn == "August") {
      return 8;
   }
   else if (mn == "September") {
      return 9;
   }
   else if (mn == "October") {
      return 10;
   }
   else if (mn == "November") {
      return 11;
   }
   else if (mn == "December") {
      return 12;
   }
   return 0;
}



// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
