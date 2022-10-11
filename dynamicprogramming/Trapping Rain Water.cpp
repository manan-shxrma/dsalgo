// https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0; 
        int j = height.size() - 1;
        int res = 0;
        int maxi = 0;
        int mini = 0;
        while(i<=j){
            mini = min(height[i],height[j]);
            maxi = max(maxi,mini);
            res += maxi - mini ;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return res ;
    }
};
