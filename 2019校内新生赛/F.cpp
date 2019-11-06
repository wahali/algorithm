#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int dp[maxn],a[maxn];
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i)scanf("%d",&a[i]);
	for(int i = 1;i <= n;++i){
		dp[a[i]] = dp[a[i]-1] + 1;
	}
	int ans = 0;
	for(int i = 1;i <= n;++i)ans = max(ans,dp[a[i]]);
	printf("%d\n",n - ans); 
	return 0;
}

