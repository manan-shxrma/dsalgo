#include<bits/stdc++.h>

using namespace std;

// this is a good implementation of stack's property as LIFO
// the next greater element of the vector is the element present in the following indices of the vector which is just greater than the concerned index
// to add to a little more twist, we made the process go in a circular fashion, that is, if the element is not found in the right, then we continue traversing in a circular order from the start of the vector again
// the overall time and space complexity involved is O(N)
// the question link of leetcode is : https://leetcode.com/problems/next-greater-element-ii/submissions
// frequently asked question in interviews

class Solution {
  public:
    vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};
int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}

