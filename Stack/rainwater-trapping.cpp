#include <bits/stdc++.h>
using namespace std;

vector<int> rainWater(int a[], int n)
{
    vector<int> v(n, -1);
    vector<int> mxL(n, -1);
    // init. first element as max element while moving from left to right
    mxL[0] = a[0]; 

    vector<int> mxR(n, -1);
    // init. last element as max element while moving from right to left
    mxR[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        mxL[i] = max(mxL[i - 1], a[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        mxR[i] = max(mxR[i + 1], a[i]);
    }

    // water stored would be (min(mxL, mxR) - a[i])
    // why min? so as to bound

    for (int i = 0; i < n; i++)
    {
        if (min(mxL[i], mxR[i]) - a[i] < 0)
        {
            v[i] = 0; // if diff is negative no need for abs() here
        }
        else
            v[i] = min(mxL[i], mxR[i]) - a[i];
    }

    return v;
}

int main()
{
    // int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int a[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(a) / sizeof(int);
    vector<int> res = rainWater(a, n);
    int water = 0;
    for (auto it : res)
    {
        cout << it << " ";
        water += it;
    }
    cout << endl;
    cout << water << endl;
}
