# Infix To Postfix Conversion
> Infix Expression: The operator is in between the two operands
Example: A + B is known as infix expression.
Postfix Expression: The operator is after the two operands
Example: BD + is known as postfix expression.

## Approach
In the process of Infix To Postfix Converting using Stack in C++, we will use the stack data structure. By scanning the infix expression from left to right, when we will get any operand, simply add them to the postfix form, and for the operator and parenthesis, add them in the stack maintaining the precedence of them.
## Code
```cpp
#include <iostream>  
#include <stack>		//Using STL for stack
using namespace std;

int priority (char alpha){						//Defining precedence of operations
    if(alpha == '+' || alpha =='-')
        return 1;
 
    if(alpha == '*' || alpha =='/')
        return 2;
 
    if(alpha == '^')
        return 3;

 
    return 0;
}
string convert(string infix)
{
    int i = 0;
    string postfix = "";
    stack <int>s;

    while(infix[i]!='\0')
    {
        // if operand add to the postfix expression
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix += infix[i];
            i++;
        }
        // if opening bracket then push the stack
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
            i++;
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if(infix[i]==')')
        {
            while(s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else            
        {
            while (!s.empty() && priority(infix[i]) <= priority(s.top())){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }


    cout << "Postfix is : " << postfix; //it will print postfix conversion  
    return postfix;
}

int main()
{
    string infix;
	cin>>infix;
    string postfix;
    postfix = convert(infix);
    
    return 0;
}
```

## Output
![image](https://user-images.githubusercontent.com/85986613/193420891-0201e3d9-6537-42f1-b519-3b1f080594dc.png)

![image](https://user-images.githubusercontent.com/85986613/193420893-7acd25d7-3f9b-4842-8935-e9413e1b6f5c.png)


