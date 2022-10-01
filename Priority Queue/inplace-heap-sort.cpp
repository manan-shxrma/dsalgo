#include <bits/stdc++.h>
using namespace std;

void heap(int *arr, int n){
    for(int i=0; i<n; i++){
        int CI = i;
        while(CI>0){
            int PI = (CI-1)/2;
            if(arr[PI]>arr[CI]){
                swap(arr[PI], arr[CI]);
                CI = PI;
            }
            else{
                break;
            }
        }
    }

    int size = n;
    while(size>=1){
        int PI = 0;
        swap(arr[0], arr[size-1]);
        size--;
        while(true){
            int lci = 2*PI + 1;
            int rci = 2*PI + 2;
            int mini = PI;
            if(lci<size && arr[mini]>arr[lci]){
                mini = lci;
            }
            if(rci<size && arr[mini]>arr[rci]){
                mini = rci;
            }
            if(mini == PI){
                break;
            }
            swap(arr[PI], arr[mini]);
            PI = mini;
        }
    }

}

int main()
{
    int arr[] = {5, 1, 2, 0, 8};
    heap(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}