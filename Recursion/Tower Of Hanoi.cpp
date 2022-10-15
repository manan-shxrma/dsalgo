Question link : https://nados.io/question/tower-of-hanoi

Tower Of Hanoi

A number n, representing number of disks A number n1, representing id of tower 1 A number n2, representing id of tower 2 A number n3, representing id of tower 3
  
  
  
  
#include<bits/stdc++.h>
using namespace std;

void toh(int n, int a, int b, int c){
    if(n==0)
      return ;
    toh(n-1, a, c, b); // recursive call .....
    cout<<n<<"["<<a<<" -> "<<b<<"]"<<endl; // print the instructions how disks are moving.
    toh(n-1, c , b , a); // recursive call......
    
  }




int  main() {

    int n;cin>>n;
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
    return 0;
  }

// Output =======================================================
1[10 -> 11]
2[10 -> 12]
1[11 -> 12]
3[10 -> 11]
1[12 -> 10]
2[12 -> 11]
1[10 -> 11]
