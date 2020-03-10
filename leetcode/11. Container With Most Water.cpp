#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;

int maxArea(vector<int>& height) {
        int ans = 0;
        int len = height.size();
        int l = 0 ,r = len - 1;
        int lh = height[l],rh = height[r];
        while(l<r){
        	ans =  max(ans,min(lh,rh)*((r-l)));
        	if(lh<=rh){
        		while(l<r&&height[l]<=lh){
        			l++;
				}
				lh = height[l];
			}
			else{
				while(l<r&&height[r]<=rh){
					r--;
				}
				rh = height[r];
			}
		}
	return ans;
    }
    

int main(){
	
	return 0;
}
