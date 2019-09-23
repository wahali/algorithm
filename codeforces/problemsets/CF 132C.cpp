#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
ll dp[105][55][2];  //下标，反转第几次，方向 
int main(){
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> s;
	cin >> n;
	int len = s.length();
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0][0] = 0;
		dp[0][0][1] = 0;
		for(int i = 1;i<=len;++i){
			for(int j = 0;j<=min(i,n);++j){
				for(int k = 0;k<=j;++k){
					if(s[i-1]=='F'){
						if(k&1){
							dp[i][j][0] = max(dp[i][j][0],dp[i-1][j-k][1]);
							dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-k][0]);
						}
						else{
							dp[i][j][0] = max(dp[i][j][0],dp[i-1][j-k][0] + 1);
							dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-k][1] - 1);
						}
					}
					else{
						if(k&1){
							dp[i][j][0] = max(dp[i][j][0],dp[i-1][j-k][0] + 1);
							dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-k][1] - 1);
						}
						else{
							dp[i][j][0] = max(dp[i][j][0],dp[i-1][j-k][1]);
							dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-k][0]);
						}
					}
				}
			}
		
		}
		ll ans = 0;
		/*
		for(int i = 0;i<=n;++i){
			cout << dp[len][i][0] << " " << dp[len][i][1] << endl;
		}
		*/
		//for(int i = 1;i<=len;++i){
			for(int j = n;j >= 0;j-=2){
			
					ans = max(ans,dp[len][j][0]);
					ans = max(ans,dp[len][j][1]);
			}
		//}
		//ans = max(dp[len][n][0],dp[len][n][1]);
		cout << ans;
	
	return 0;
}
/*
FFTFFTFFF
1
FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

50
(100)
*/
