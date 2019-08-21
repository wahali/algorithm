#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
ll mp(ll a,ll b){
	ll ans = 1,tem = a;
	while(b){
		if(b&1)ans*=tem;
		tem *=tem;
		b >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	ll n,l,r;
	cin >> n >> l >> r;
	ll ans = mp(2,l)-1+n-l;
	cout << ans <<" ";
	ll t = min(n,r);
	ll tt = mp(2,t);
	//cout << tt << endl;
	ans = tt-1 + tt/2*(n-t);
	cout << ans ;
	return 0;
}
