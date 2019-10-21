#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
ll p[maxn],sum[maxn];
ll q,n,x,y,a,b,k,l,r,mid;
bool check(int t){
	int ad = t/(a*b/__gcd(a,b));
	ll tot = 0;
	tot += (sum[n]-sum[n-ad])/100*(x+y);
	if(x < y){
		tot += (sum[n-ad]-sum[n-ad-(t/b-ad)])/100 * y;
		tot += (sum[n-ad-(t/b-ad)] - sum[n-ad-(t/b-ad) -(t/a-ad)])/100 * x;
		
	}
	else{
		tot += (sum[n-ad]-sum[n-ad-(t/a-ad)])/100 * x;
		tot += (sum[n-ad-(t/a-ad)] - sum[n-ad-(t/b-ad) -(t/a-ad)])/100 * y;
	}
	//cout << t << ' ' << tot << endl;
	if(tot>=k)return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(false);
	
	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 1;i <= n;++i)cin >> p[i];
		sort(p+1,p+1+n);
		for(int i =1;i <= n;++i)sum[i] = sum[i-1]+p[i];
		cin >> x >> a >> y >> b;
		cin >> k;
		l = 0,r = n+1;
		while(l<r){
			mid = (l+r)>>1;
			if(check(mid))r = mid;
			else l = mid + 1;
		}
		if(l==0||l>n)cout << -1 << endl;
		else cout << l << endl;
	}

	return 0;
}

