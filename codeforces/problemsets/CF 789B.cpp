#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
set<int> s;
int main(){
	ios::sync_with_stdio(false);
	ll b1,q,l,m;
	cin >> b1 >> q >> l >> m;
	int tem;
	for(int i = 1;i <= m;++i){
		cin >> tem;
		s.insert(tem);
	} 
	if(abs(b1) > l){
		cout << 0;
		return 0;
	}
	if(b1 == 0){
		if(s.count(0)){
			cout << 0;
			return 0;
		}
		else {
			cout << "inf";
			return 0;
		}
	}
	else if(q == 0){
		int ans = 0;
		if(s.count(b1)==0&&abs(b1)<=l)ans++;
		if(s.count(0)==0){
			cout << "inf" ;
			return 0;
		}
		else {
			cout << ans ;
			return 0;
		}
	}
	else if(q == 1){
		int ans = 0;
		if(s.count(b1)==0&&abs(b1)<=l){
			cout << "inf";
			return 0;
		}
		cout << ans ;
		return 0;
	}
	else if(q==-1){
		int ans = 0;
		if(abs(b1)<=l&&(s.count(b1)==0||s.count(-b1)==0)){
			cout << "inf";
			return 0;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	else {
	 ll ans = 0;
	 while(abs(b1)<=l){
	 	if(s.count(b1)==0)ans++;
	 	b1 *= q;
	 }
	 cout << ans ;
	}
	return 0;
}

