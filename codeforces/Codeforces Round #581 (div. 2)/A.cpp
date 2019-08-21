#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	if(s.length()==1){
		cout << 0;
		return 0;
	}
	ll ans = 0;
	ll num =0;
	for(int i =0;i<s.length();++i)if(s[i]=='1')num++;
	ans +=(s.length()-2+1)/2;
	if((s.length()-2)%2==1&&num==1)ans--;
	cout << ans + 1;
	return 0;
}
