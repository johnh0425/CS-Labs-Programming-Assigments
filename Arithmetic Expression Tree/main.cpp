#include <iostream>
#include "arithmeticExpression.h"

using namespace std;

int main(){
    std::string expr1 = "a+b*c";
    arithmeticExpression ex1(expr1);
    ex1.buildTree();
    std::cout<<"expression 1: "<<expr1<<std::endl;
    std::cout<<"infix: "; ex1.infix(); std::cout<<std::endl;
    std::cout<<"prefix: "; ex1.prefix(); std::cout<<std::endl;
    std::cout<<"postfix: "; ex1.postfix(); std::cout<<std::endl;
    ex1.visualizeTree("expr1.dot");
    std::cout<<endl;

    string expr2 = "(a+b)*(c-d)";
    arithmeticExpression ex2(expr2);
    ex2.buildTree();
    std::cout<<"expression 2: "<<expr2<<std::endl;
    std::cout<<"infix: "; ex2.infix(); std::cout<<std::endl;
    std::cout<<"prefix: "; ex2.prefix(); std::cout<<std::endl;
    std::cout<<"postfix: "; ex2.postfix(); std::cout<<std::endl;
    ex2.visualizeTree("expr2.dot");
    std::cout<<endl;

    string expr3 = "a + b * c - ( d * e + f ) * g";
    arithmeticExpression ex3(expr3);
    ex3.buildTree();
    std::cout<<"expression 3: "<<expr3<<std::endl;
    std::cout<<"infix: "; ex3.infix(); std::cout<<std::endl;
    std::cout<<"prefix: "; ex3.prefix(); std::cout<<std::endl;
    std::cout<<"postfix: "; ex3.postfix(); std::cout<<std::endl;
    ex3.visualizeTree("expr3.dot");
    std::cout<<endl;

    // Testcases

    string expr4 = "a + b + c + d";
    arithmeticExpression ex4(expr4);
    ex4.buildTree();
    std::cout<<"expression 4: "<<expr4<<std::endl;
    std::cout<<"infix: "; ex4.infix(); std::cout<<std::endl;
    std::cout<<"prefix: "; ex4.prefix(); std::cout<<std::endl;
    std::cout<<"postfix: "; ex4.postfix(); std::cout<<std::endl;
    ex4.visualizeTree("expr4.dot");
    std::cout<<endl;

    string expr5 = "( a - b ) * c";
    arithmeticExpression ex5(expr5);
    ex5.buildTree();
    std::cout<<"expression 5: "<<expr5<<std::endl;
    std::cout<<"infix: "; ex5.infix(); std::cout<<std::endl;
    std::cout<<"prefix: "; ex5.prefix(); std::cout<<std::endl;
    std::cout<<"postfix: "; ex5.postfix(); std::cout<<std::endl;
    ex5.visualizeTree("expr5.dot");
    std::cout<<endl;

    string expr6 = "( ( ( a + b ) * c ) - d ) ";
    arithmeticExpression ex6(expr6);
    ex6.buildTree();
    std::cout<<"expression 6: "<<expr6<<std::endl;
    std::cout<<"infix: "; ex6.infix(); std::cout<<std::endl;
    std::cout<<"prefix: "; ex6.prefix(); std::cout<<std::endl;
    std::cout<<"postfix: "; ex6.postfix(); std::cout<<std::endl;
    ex6.visualizeTree("expr6.dot");
    std::cout<<endl;

    string expr7 = "a * b - c + d * ( e - f )";
    arithmeticExpression ex7(expr7);
    ex7.buildTree();
    std::cout<<"expression 7: "<<expr7<<std::endl;
    std::cout<<"infix: "; ex7.infix(); std::cout<<std::endl;
    std::cout<<"prefix: "; ex7.prefix(); std::cout<<std::endl;
    std::cout<<"postfix: "; ex7.postfix(); std::cout<<std::endl;
    ex7.visualizeTree("expr7.dot");
    std::cout<<endl;
    return 0;
}