#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int rec_linear_search(int arr[], int left, int right, int x) {
    int result;
    if (right < left)        // The array is exhausted so return -1
        return -1;
    if (arr[left] == x)        // If element found return position
        return left;
    // Call the function again with new subarray from next element.
    result = rec_linear_search(arr, left+1, right, x);     
    return result;    // return the result to the calling function.
}

int main() {
    int array[]={10,11,12,13,14,25,26,37,48,29};
    int x=13;    // Searched Element.
    int n = sizeof(array)/sizeof(array[0]);
    int loc=rec_linear_search(array,0,n, x);    // Call the search function

    if(loc != -1)
        cout<<"Element found at location : "<<loc;
    else
        cout<<"Element not present in the array.";
    return 0;
}
