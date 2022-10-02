#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> permute(vector<int>&nums,int i){

	vector<vector<int>>answer;

	

	if(i==nums.size()){
		answer.push_back(nums);

	}

	for(int j=i;j<nums.size();j++){

		swap(nums[i],nums[j]);
		permute(nums,i+1);
		swap(nums[i],nums[j]);

	}

return answer;


}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	vector<int> nums={1,2,3};

	vector<vector<int>>ans=permute(nums,0);

	  for (int p = 0; p < ans.size(); p++) {
        for (int j = 0; j < ans[p].size(); j++)
            cout << ans[p][j]<< " ";
        cout << endl;
    }

	return 0;

}
