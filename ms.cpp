#include<iostream>
using namespace std;

void mergeArrays(int x[],int y[],int a[],int s,int e){

int mid=(s+e)/2;
int i=s;
int j=mid+1;
int k=s;
while(i<=mid && j<=e){
    if(x[i]<y[j]){
        a[k]=x[i];
        i++;
        k++;
    }
    else{
        a[k]=y[j];
        j++;
        k++;
    }
    //now either i=mid+1 or j=end+1
    //one of these two conditions will become true
    //hence a single element will be left out,
    //to compensate for that
    while(i<=mid){
        a[k]=x[i];
        i++;
    }

    while(j<=e){
        a[k]=y[j];
        j++;
    }

}
}


void mergeSort(int a[],int s,int e){
    if(s>=e){
        return;
    }

    int mid=s+(e-s)/2;
    int x[100000],y[100000];
    for(int i=s;i<=mid;i++){
        x[i]=a[i];


    }
    for(int i=mid+1;i<=e;i++){
        y[i]=a[i];
    }

    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    mergeArrays(x,y,a,s,e);

}

int main(){

    int a[]={23,1,21,-3,45,67,89,111,656,0,-10};

    mergeSort(a,0,10);
    for(int i=0;i<11;i++){
        cout<<a[i]<<" ";
    }

    return 0;


}