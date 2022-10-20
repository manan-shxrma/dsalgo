// You are playing a computer game. To pass the current level, you have to kill a big horde of monsters. In this horde, there are n monsters standing in the row, numbered from 1 to n. The i-th monster has ai health and a special "Death's Blessing" spell of strength bi attached to it.

// You are going to kill all of them one by one. It takes exactly h seconds to kill a monster with health h.

// When the i-th monster dies, it casts its spell that increases the health of its neighbors by bi (the neighbors of the j-th monster in the row are the monsters on places j−1 and j+1. The first and the last monsters have only one neighbor each).

// After each monster is killed, the row shrinks, so its former neighbors become adjacent to each other (so if one of them dies, the other one is affected by its spell). For example, imagine a situation with 4 monsters with health a=[2,6,7,3] and spells b=[3,6,0,5]. One of the ways to get rid of the monsters is shown below:

// 2	6	7	3	−→6 s	8	13	3	−→−13 s	8	3	−→8 s	6	−→6 s	{}
// 3	6	0	5	3	0	5	3	5	5	
// The first row represents the health of each monster, the second one — the power of the spells.
// As a result, we can kill all monsters in 6+13+8+6 = 33 seconds. Note that it's only an example and may not be the fastest way to get rid of the monsters.

// What is the minimum time required to kill all monsters in the row?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases.

// The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of monsters in the row.

// The second line contains n integers a1,a2,…,an (1≤ai≤109) — the initial health of corresponding monsters.

// The third line contains n integers b1,b2,…,bn (0≤bi≤109), where bi is the strength of the spell for the i-th monster.

// It's guaranteed that the sum of n doesn't exceed 2⋅105.

// Output
// For each test case, print one integer — the minimum possible total time to kill all monsters.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    long long int sum1 = 0, sum2 = 0;
    long long int max1 = 0;
    for (int i = 0; i < t; i++)
    {
        sum1 = 0;
        sum2 = 0;
        max1 = 0;

        int n;
        cin >> n;
        int arr[n];
        int arr1[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum1 = sum1 + arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
            sum2 = sum2 + arr1[i];
            if (arr1[i] >= max1)
            {
                max1 = arr1[i];
            }
        }
        sum2 = sum2 - max1;
        cout << sum1 + sum2 << endl;
    }
}
