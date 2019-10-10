#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int a[105];

int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	int tem;
	for(int i = 1;i <= n;++i){
		cin >> tem;
		a[tem%k]++;
	}
	ll ans = 0;
	for(int i = 1;i<=k/2;++i){
		if(i!=k-i){
			ans += 2*min(a[i],a[k-i]);
		}
		else{
			ans+=a[i]/2*2;
		}
	}
	ans += a[0]/2*2;
	cout << ans;
	return 0;
}
