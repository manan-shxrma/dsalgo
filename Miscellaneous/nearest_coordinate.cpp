class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) { 
        int minDist = INT_MAX;
        int returnIndex = -1;
        int sum = 0;
        for(int it = 0; it < points.size(); it++){
            if(points[it][0] == x || points[it][1] == y){
                sum = (abs(x - points[it][0]) + abs(y - points[it][1]));
                if(minDist > sum){
                    minDist = sum;
                    returnIndex = it;
                }
            }
        }
        return returnIndex;
    }
};