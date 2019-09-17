#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int a[5000];
struct T{
	int tt,c;
}t[2005];
ll dp[5005];
bool cmp(T a,T b){
	return a.c < b.c ;
}
int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll t,c;
	for(int i = 1;i <= 2000;++i)dp[i] = 9e18;
	for(int i = 1;i <= n;++i){
		cin >> t >> c;
		for(int j = n; j>=0;--j){
			dp[min(n,j+t+1)] = min(dp[min(n,j+t+1)],dp[j] + c);
		}
	}
	cout << dp[n];
	return 0;
}

