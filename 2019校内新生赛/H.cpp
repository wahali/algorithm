#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'0
ll n,k,x;
ll dp[3000][3000];
int main() {
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i < n; ++ i)scanf("%lld",&x);
	dp[0][0] = 1;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= k;++j){
			dp[i][j] = ((dp[i-1][j-1]*((k-j+1)%mod))%mod+(dp[i-1][j]*((j-1)%mod))%mod)%mod;
		}
	}
	printf("%lld",dp[n][k]);
	return 0;
}

