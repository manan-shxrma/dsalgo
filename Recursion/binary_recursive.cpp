#include<iostream>
using namespace std;

int recBinarySearch(int A[], int n, int key, int l, int h){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key==A[mid]){
            return mid;
        }
        else if(key>A[mid]){
          return recBinarySearch(A, n, key, mid+1,h);
        }
        else{
            return recBinarySearch(A, n, key, l,mid-1);
        }
    }
    return -1;

}

int main(){

   cout<<"SEJAL KOTHARI(209303070)"<<endl;

    int A[8];
   //={1,3,5,8,45,67,89,91};
    int n = sizeof(A)/sizeof(int);
     cout<<"Array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<"Element Position: "<<endl;

    cout<<recBinarySearch(A, n,100,0,n-1)<<endl;

    return 0;
}