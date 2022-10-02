#include<bits/stdc++.h>
using namespace std;

// the method implied here is of stack
// the LIFO principle of stack plays an imminent role
// the overall time and space complexity is O(N)
// the characters are checked in this format:
// the prior character is an opening bracket, followed by a closing bracket, then all fine, continue
// the prior character is not there, but there is a closing bracket, so return false, invalid bracket expression
// the whole process works fine, and returns an empty stack at the end, indication that all the brackets are articulately balanced, return true
// a must question for CP as well as DSA
// leetcode question link : https://leetcode.com/problems/valid-parentheses/

bool isValid(string s) {
        stack<char>st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
    }
int main()
{
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}