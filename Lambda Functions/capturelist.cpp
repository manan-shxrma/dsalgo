//Capture List

#include<iostream>
using namespace std;

int main(){

    double a{10};
    double b{20};

    int c{42};
    int d{52};
//capture list is used so that the lambda functions can be can
//have access to outer variables which are
//outside the scope of the function

//the important thing to note is that the values are going through the capture list and not the parameter list
    auto func=[a,b](){
        std::cout<<"a+b"<<a+b<<std::endl;
    };

    func();


    //Capturing by value
    /*
    Now when we capture by value we create a copy of the variable and
    the original variable remains the same

    for example*/
    auto funcx=[c](){
        std::cout<<"Inner value: "<<c<<std::endl;
    };


    for(int i=0;i<5;i++){
        std::cout<<"Outer value: "<<c<<std::endl;
        funcx();
        ++c;


    }


     auto funcy=[&d](){
        std::cout<<"Inner value: "<< &d <<std::endl;
    };


    for(int i=0;i<5;i++){
        std::cout<<"Outer value: "<< &d <<std::endl;
        funcy();
        ++d;


    }

    

    ///now what we will observe is that the c in the lambda
    ///function is passed by value hence a copy of it exists inthe 
    ///lambda function

    //therefor the c in for loop will increment 
    ///while the c in the lambda function will stay the same


    return 0;
}