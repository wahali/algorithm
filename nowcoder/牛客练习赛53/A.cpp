#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
const int mod = 1e9+7;
ll ans[maxn][2];
#define debug(a) cout<<#a<<": "<<a<<'\n'
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ans[1][0] = ans[1][1] = 1;
	for(int i = 2;i<=n;++i){
		ans[i][1] = ans[i-1][0] % mod;
		ans[i][0] = (ans[i-1][0]+ans[i-1][1])%mod;
	}
	cout << (ans[n][0]+ans[n][1])%mod;
	return 0;
}

