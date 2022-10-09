//In this program we define an operator '+' such that it add marks of each subject of two object

#include<bits/stdc++.h>
using namespace std;

//declaring class studentMarks which contain 5 subjects denoting respective marks
class studentMarks{
    public:
    int english;
    int hindi;
    int maths;
    int science;
    int  sst;

//here we are defining operator '+' for adding marks
//this will automatically called when '+' is used between two studentMarks objects
    
    studentMarks operator+(studentMarks const &obj){
    studentMarks overall;
    overall.english=english+obj.english;
    overall.hindi=hindi+obj.hindi;
    overall.maths=maths+obj.maths;
    overall.science=science+obj.science;
    overall.sst=sst+obj.sst;

    return overall;    //as a result '+' operator will return another object of studentMarks class
}

};



int main(){
    
    //here we are declaring objects of class which gives marks of each subject
    
    studentMarks HalfYearly;
    HalfYearly.english=20;
    HalfYearly.hindi=15;
    HalfYearly.maths=18;
    HalfYearly.science=17;
    HalfYearly.sst=19;

     studentMarks Yearly;
    Yearly.english=80;
    Yearly.hindi=75;
    Yearly.maths=68;
    Yearly.science=67;
    Yearly.sst=69;

   //this is the calling of '+' operator here it will return another object stored in Total 
    studentMarks Total=HalfYearly+Yearly;
    
    //getting total marks of the student 
    cout<<"Total Marks of Student are:"<<endl;
    cout<<"English: "<<Total.english<<endl;
    cout<<"Hindi  : "<<Total.hindi<<endl;
    cout<<"Maths  : "<<Total.maths<<endl;
    cout<<"Science: "<<Total.science<<endl;
    cout<<"SSt.   : "<<Total.sst<<endl;


return 0;

}
