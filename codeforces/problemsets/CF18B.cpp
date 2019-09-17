#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int main(){
	ios::sync_with_stdio(false);
	ll n,d,m,l;
	cin >> n >> d >> m >> l;
	ll ans = 1;
	ll zuo,you;
	for(int i = 1;i <= n ;++i){
		zuo = i * m;
		you = (i-1)*m + l;
		ans = (you + d) / d;
		if(ans*d<zuo)break;
	}
	cout << ans * d;
	return 0;
}

