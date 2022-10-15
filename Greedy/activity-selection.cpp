// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.

    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(make_pair(start[i], end[i]));
        }

        int count = 1;
        sort(v.begin(), v.end(), comp);

        int i = 0, j = 1;
        while (j < n)
        {
            if (v[i].second < v[j].first)
            {
                count++;
                i = j;
                j++;
            }
            else
                j++;
        }

        return count;
    }
};
