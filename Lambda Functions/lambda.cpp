#include<bits/stdc++.h>
using namespace std;

///lambda function signature

///syntax
///lambda function signature :
///[capture list] (parameters) -> return type{
    ///function body
///}
///return type is optional

auto func=[](){
    std::cout<<"Hello World!"<<std::endl;
};


///it is possible to call a lambda function directly without calling it a name
/*
[](){
    std::cout<<"Hello world"<<std::endl;
}();
*/

// Lambda function that takes parameters
auto func1=[](double a,double b){
    std::cout<<"a+b: "<<(a+b)<<std::endl;
};


//lambda function that returns something
auto funcx=[](double a,double b){
    return a+b;
};

auto func3=[](double a,double b)->int{
    return a*b;
};

int main(){
func();
func1(10,20);
func1(5,7);

double a{132.345};
double b{234.564};

std::cout<<func3(a,b)<<std::endl;
std::cout<<sizeof(func3)<<std::endl;
///funcx(10,20)
///only calling the function wont print it because we are returning the value

std::cout<<funcx(10,20)<<std::endl;
[](double a,double b){
    std::cout<<"a+b :"<<(a+b)<<std::endl;

}(12.1,5.7);

///we can also do this function
std::cout<<"result: "<<[](double a,double b){
    return a+b;
}(10,60)<<std::endl;

return 0;

}


/*
Lambda function that takes parameters
[](double a.double b){
    std::cout<<"a+b :"<<(a+b)<<std::endl;

}(12.1,5.7)
*/


/*
Lambda function that returns something

auto result=[](double a, double b){
    return(a+b);
}(12.1,5.7);
std::cout<<"result"<<result<<std::endl;
*/

/*
Specify return type explicitly
auto result=[](double a,double b)->double{
    return(a+b);

}(12.1,5.7);
std::cout<<"result"<<result<<std::endl;
*/