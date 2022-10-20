#include<iostream>  
#include<stack>  
using namespace std;  
// defines the Boolean function for operator, operand, equalOrhigher precedence and the string conversion function.  
bool IsOperator(char);  
bool IsOperand(char);  
bool eqlOrhigher(char, char);  
string convert(string);  
  
int main()  
{  
string infix_expression, postfix_expression;  
int ch;  
do  
{  
cout << " Enter an infix expression: ";  
cin >> infix_expression;  
 postfix_expression = convert(infix_expression);  
 cout << "\n Your Infix expression is: " << infix_expression;  
cout << "\n Postfix expression is: " << postfix_expression;  
cout << "\n \t Do you want to enter infix expression (1/ 0)?";  
cin >> ch;  
//cin.ignore();   
} while(ch == 1);  
return 0;  
}  
  
// define the IsOperator() function to validate whether any symbol is operator.  
/* If the symbol is operator, it returns true, otherwise false. */  
bool IsOperator(char c)  
{  
if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )  
return true;     
return false;  
}  
  
// IsOperand() function is used to validate whether the character is operand.  
bool IsOperand(char c)  
{  
if( c >= 'A' && c <= 'Z')  /* Define the character in between A to Z. If not, it returns False.*/  
return true;  
if (c >= 'a' && c <= 'z')  // Define the character in between a to z. If not, it returns False. */  
return true;  
if(c >= '0' && c <= '9')   // Define the character in between 0 to 9. If not, it returns False. */  
return true;  
return false;  
}  
// here, precedence() function is used to define the precedence to the operator.  
int precedence(char op)  
{  
if(op == '+' || op == '-')                   /* it defines the lowest precedence */  
return 1;  
if (op == '*' || op == '/')  
return 2;  
if(op == '^')                                  /* exponent operator has the highest precedence * 
return 3;       
return 0; 
} 
/* The eqlOrhigher() function is used to check the higher or equal precedence of the two operators in infix expression. */  
bool eqlOrhigher (char op1, char op2)  
{  
int p1 = precedence(op1);  
int p2 = precedence(op2);  
if (p1 == p2)  
{  
if (op1 == '^' )  
return false;  
return true;  
}  
return  (p1>p2 ? true : false);  
}  
  
/* string convert() function is used to convert the infix expression to the postfix expression of the Stack */  
string convert(string infix)  
{  
stack <char> S;  
string postfix ="";    
char ch;  
  
S.push( '(' );  
infix += ')';  
  
for(int i = 0; i<infix.length(); i++)  
{  
ch = infix[i];  
  
if(ch == ' ')  
continue;  
else if(ch == '(')  
S.push(ch);  
else if(IsOperand(ch))  
postfix += ch;  
else if(IsOperator(ch))  
{  
while(!S.empty() && eqlOrhigher(S.top(), ch))  
{  
postfix += S.top();  
S.pop();  
}  
S.push(ch);  
}  
else if(ch == ')')  
{  
while(!S.empty() && S.top() != '(')  
{  
postfix += S.top();  
S.pop();  
}  
S.pop();  
}  
}  
return postfix;  
}  
