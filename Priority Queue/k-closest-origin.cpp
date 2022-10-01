// k closest points to origin

#include <bits/stdc++.h>
#include <map>
using namespace std;

int pow(int a, int b)
{
    if (b == 0)
        return a;

    while (b)
    {
        if (b % 2 == 0)
        {
            int temp = pow(a, b / 2);
            return temp * temp;
        }
        else
        {
            return a * pow(a, b / 2);
        }
    }
}

struct compare
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (pow(p1.first, 2) + pow(p1.second, 2) == pow(p2.first, 2) + pow(p2.second, 2))
        {
            return p1.first > p2.first;
        }
        else
            return p1.second > p2.second;
    }
};

map<int, int> kClosest(map<int, int> a, int k)
{
    map<int, int> m;

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq(a.begin(), a.end());

    while (k--)
    {
        m.insert(make_pair(pq.top().first, pq.top().second));
        pq.pop();
    }
    return m;
}

int main()
{
    map<int, int> m;
    int k = 2;

    m.insert({1, 3});
    m.insert({-2, 2});
    m.insert({5, 8});
    m.insert({0, 1});

    map<int, int> v = kClosest(m, k);
    for (auto it : v)
    {
        cout << it.first << ", " << it.second << endl;
    }
}
