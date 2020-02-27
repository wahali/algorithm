#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int j,k,sum;
    for(int i = 0;i<nums.size();++i){
    	if(i>0&&(nums[i-1]==nums[i]))continue;
    	j = i+1;
    	k = nums.size()-1;
    	while(j<k){
    		sum = nums[i]+nums[j]+nums[k];
    		if(sum<0)j++;
    		else if(sum > 0)k--;
    		else {
    			ans.push_back(vector<int>{nums[i],nums[j],nums[k]});
    			do{
					j++;
				}while(j<k&&nums[j-1]==nums[j]);
    			do{
					k--;
				}while(j<k&&nums[k]==nums[k+1]);
			}
		}
	}
	return ans;
}

int main(){
	
	return 0;
}
