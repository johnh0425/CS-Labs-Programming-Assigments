#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      Rational(int d); 
      Rational(int n, int d); 
      Rational add(const Rational &B) const; 
      Rational subtract(const Rational &B) const; 
      Rational multiply(const Rational &B) const; 
      Rational divide(const Rational &B) const;
      void simplify();
      void display() const;
   private:
      int gcd(int n, int d) const;
};

// Implement Rational class member functions here
Rational::Rational() {
   numerator = 0;
   denominator = 1;
}

Rational::Rational(int n) {
   numerator = n;
   denominator = 1;
}

Rational::Rational(int n, int d) {
   numerator = n;
   denominator = d;
}

Rational Rational::add(const Rational &B) const {
   int num;
   int den;
   num = ((this->numerator * B.denominator) + (this->denominator * B.numerator)) ;
   den = (this->denominator * B.denominator);
   return Rational(num,den);
}

Rational Rational::subtract(const Rational &B) const {
   int num;
   int den;
   num = ((this->numerator * B.denominator) - (this->denominator * B.numerator));
   den = (this->denominator * B.denominator);
   return Rational(num,den);
}

Rational Rational::multiply(const Rational &B) const {
   int num;
   int den;
   num = (this->numerator * B.numerator);
   den = (this->denominator * B.denominator);
   return Rational(num,den);
}

Rational Rational::divide(const Rational &B) const {
   int num;
   int den;
   num = (this->numerator * B.denominator);
   den = (this->denominator * B.numerator);
   return Rational(num,den);
}

void Rational::simplify() {
   int factor;
   factor = gcd(numerator, denominator);
   numerator = numerator / factor;
   denominator = denominator / factor;
}

void Rational::display() const {
   cout << numerator << " / " << denominator;
}

int Rational::gcd(int n, int d) const {
   while (n != d) {
      if (d > n) {
         d = d - n;
      }
      else {
         n = n - d;
      }
   }
   return n;
}



// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}


void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

