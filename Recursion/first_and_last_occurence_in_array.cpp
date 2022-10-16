#include<iostream>
using namespace std;
int firstocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i+1,key);
}
int lastocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    int lastval=lastocc(arr,n,i+1,key);
    if(lastval!=-1){
        return lastval;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}
int main(){
    int arr[]={2,4,5,7,2,4,2,6,8};
    cout<<firstocc(arr,9,0,2)<<endl;
    cout<<lastocc(arr,9,0,2)<<endl;

    return 0;
}
