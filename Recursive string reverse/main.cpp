#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
   if (s.size() <= 1) {
      return;
   }
   char c = s.at(0);
   s = s.substr(1, s.size() - 1);
   flipString(s);
   s = s + c;
}


