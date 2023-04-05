#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, const IntList &rhs) {
   IntNode *temp = rhs.head;
    if (rhs.head == nullptr) {
        return out;
    }
    if (temp -> next == nullptr) {
      out << temp->value;
      return out;
    }
   out << temp->value << " ";
   temp = temp->next;
   out << temp;
   return out;
}

ostream & operator<<(ostream &out, IntNode *temp) {
   if (temp == nullptr) {
      return out;
   }
   if (temp -> next == nullptr) {
      out << temp->value;
      return out;
   }
   out << temp->value << " ";
   temp = temp->next;
   out << temp;
   return out;
}

bool IntList::exists(int e) const {
   if (head == nullptr) {
      return false;
   }
   if (head->value == e) {
      return true;
   }
   return exists(head->next, e);
}

bool IntList::exists(IntNode *temp, int e) const {
   if (temp == nullptr) {
      return false;
   }
   if (temp->value == e) {
      return true;
   }
   return exists(temp->next, e);
}
