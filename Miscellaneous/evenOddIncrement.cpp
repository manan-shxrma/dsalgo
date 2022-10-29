// You are given n of integers a1,a2,…,an. Process q queries of two types:

// query of the form "0 xj": add the value xj to all even elements of the array a,
// query of the form "1 xj": add the value xj to all odd elements of the array a.
// Note that when processing the query, we look specifically at the odd/even value of ai, not its index.

// After processing each query, print the sum of the elements of the array a.

// Please note that the answer for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language (like long long for C++).

// Input
// The first line of the input contains an integer t (1≤t≤104) — the number of test cases.

// The descriptions of the test cases follow.

// The first line of each test case contains two integers n and q (1≤n, q≤105) — the length of array a and the number of queries.

// The second line of each test case contains exactly n integers: a1,a2,…,an (1≤ai≤109) — elements of the array a.

// The following q lines contain queries as two integers typej and xj (0≤typej≤1, 1≤xj≤104).

// It is guaranteed that the sum of values n over all test cases in a test does not exceed 105. Similarly, the sum of values q over all test cases does not exceed 105.

// Output
// For each test case, print q numbers: the sum of the elements of the array a after processing a query.


#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
 
        long long int n, q, even = 0, odd = 0, temp1, temp2;
        long long int odd_sum = 0, even_sum = 0, sum = 0;
        cin >> n >> q;
        long long int arr[n];
 
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                even_sum = even_sum + arr[i];
                even++;
            }
            if (arr[i] % 2 != 0)
            {
                odd_sum = odd_sum + arr[i];
                odd++;
            }
        }
        long int type, x;
 
        for (int i = 0; i < q; i++)
        {
            sum =0 ;
            cin >> type >> x;
 
            if (type == 0)
            {   even_sum = even_sum + (even * x);
                sum = odd_sum + even_sum;
            }
            if (type == 1)
            {   odd_sum = odd_sum + (odd * x);
                sum = even_sum + odd_sum;
            }
            cout << sum << endl;
            if (x % 2 != 0)
            {
           if (type == 0)
            {
                odd = odd +even;
                even = 0;
                odd_sum = even_sum + odd_sum;
                even_sum = 0;
            }
            if (type == 1)
            {
                even = even + odd;
                odd = 0;
                even_sum = even_sum + odd_sum;
                odd_sum = 0;
 
            }
            }
        }
    }
}