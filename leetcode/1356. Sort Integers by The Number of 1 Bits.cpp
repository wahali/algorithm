#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;
    struct tt{
	int x,num;
};

static bool cmp(tt a,tt b){
	if(a.num < b.num)return true;
	else if(a.num == b.num)return a.x < b.x;
	else return false;
}

vector<int> sortByBits(vector<int>& arr) {
       struct tt t[arr.size()+5];
	   for(int i = 0;i < arr.size();++i){
       	t[i].x = arr[i];
       	int tem = t[i].x,cnt = 0;
       	while(tem){
       		if(tem%2==1)cnt++;
       		tem/=2;
		}
		t[i].num = cnt;
	   } 
	   sort(t,t+arr.size(),cmp);
	   vector<int> ans;
	   for(int i = 0;i < arr.size();++i)ans.emplace_back(t[i].x);
	   return ans;
}

int main(){
	
	return 0;
}
