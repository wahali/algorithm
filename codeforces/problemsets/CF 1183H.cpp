#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
ll pre[30];
ll dp[105][105];
char s[105];

int main(){
	ios::sync_with_stdio(false);
	ll n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;++i)cin >> s[i];
	dp[0][0] = 1;
	for(int i = 1;i <= n;++i){
		dp[i][0] = 1;
		for(int j = 1;j <= i;++j){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			int pos = pre[s[i]-'a'];
			if(pos&&pos - i + j>=0)
				dp[i][j] -= dp[pos-1][pos-i+j];
		}
		pre[s[i]-'a'] = i;
	}
	ll cnt = 0;
	ll ans =0;
	//for(int i = 0;i<=n;++i)cout << dp[n][i] << endl;
	for(int j = 0;j<=n;++j){
		if(dp[n][j]>=k){
			ans += k * j;
			k = 0;
			break;
		}
		else {
			k -= dp[n][j];
			ans += dp[n][j] * j;
		}
	}
	if(k!=0)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
