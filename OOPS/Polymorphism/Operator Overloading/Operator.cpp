#include<bits/stdc++.h>
using namespace std;

class studentMarks{
    public:
    int english;
    int hindi;
    int maths;
    int science;
    int  sst;


    studentMarks operator+(studentMarks const &obj){
    studentMarks overall;
    overall.english=english+obj.english;
    overall.hindi=hindi+obj.hindi;
    overall.maths=maths+obj.maths;
    overall.science=science+obj.science;
    overall.sst=sst+obj.sst;

    return overall;
}

};



int main(){
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

    studentMarks Total=HalfYearly+Yearly;

    cout<<"Total Marks of Student are:"<<endl;
    cout<<"English: "<<Total.english<<endl;
    cout<<"Hindi  : "<<Total.hindi<<endl;
    cout<<"Maths  : "<<Total.maths<<endl;
    cout<<"Science: "<<Total.science<<endl;
    cout<<"SSt.   : "<<Total.sst<<endl;


return 0;

}