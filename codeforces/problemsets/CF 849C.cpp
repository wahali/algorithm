#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int main(){
	ios::sync_with_stdio(false);
	ll k;
	cin >> k;
	if(k==0){
		cout << "a";
		return 0;
	}
	string s="";
	ll cnt = 1;
	int tag = 0;
	while(k){
	cnt = 1;
	while(cnt*(1+cnt)/2 <= k)cnt++;
	k-=(cnt-1)*cnt/2;
	for(int i = 1;i <= cnt;++i)s = s + char('a'+tag);
	tag++;
	}
	cout << s;
	return 0;
}

