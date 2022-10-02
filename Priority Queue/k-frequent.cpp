#include <bits/stdc++.h>
using namespace std;

vector<int> kFrequent(int a[], int n, int k)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // for (auto i = m.begin(); i != m.end(); i++)
    // {
    //     pq.push(make_pair(i->second, i->first));
    //     if(pq.size()>k){
    //         pq.pop();
    //     }
    // }

    // other method
    for (auto it : m)
    {
        pq.push(make_pair(it.second, it.first));
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> v;

    while (k--)
    {
        v.push_back(pq.top().second);
        pq.pop();
    }
    return v;
}

int main()
{
    int a[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(a) / sizeof(int);
    int k = 2;
    vector<int> v = kFrequent(a, n, k);
    for (auto it : v)
    {
        cout << it << " ";
    }
}
