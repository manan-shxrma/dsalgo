#include<iostream>
using namespace std;

// via recursion 

bool checkPrime(int n,int i = 2){
    if(n <=2){
        if(n==2)return true;
        else false;
    }

    if(n%i==0){
        return false;
    }

    if(i*i >n){
        return true;
    }

    return checkPrime(n,i+1);
}


int main(){
    int n;
    cin>>n;
    if(checkPrime(n))cout<<"True";
    else cout<<"False";

}
