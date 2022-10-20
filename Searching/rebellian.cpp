#include <iostream>
using namespace std;
int main()
{
    int t, s = 1, state = 0, f=0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {   f=0;
        int n;
        state = 0;
        cin >> n;
 
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i]==0){
                f++;
            }
        }
        for(int i=0;i<f;i++){
            if (arr[i]==1){
                state++;
            }
        }
        cout << state << endl;
    }
}