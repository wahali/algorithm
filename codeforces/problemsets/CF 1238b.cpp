#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int a[maxn],sum[maxn];
int q,n,R,tem,l,r,mid,size;
bool check(int x){
	if(a[size-1-x]<=x*R)return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> q;
	while(q--){
		cin >> n >> R;
		for(int i = 1;i <= n;++i)cin >> a[i];
		sort(a+1,a+1+n);
		size = unique(a+1,a+1+n)-a;
//		for(int i = 1;i < size;++i)cout << a[i] << ' ';
		l = 0,r = size;
		while(l<r){
			mid = (l+r) >> 1;
			if(check(mid))r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
	}

	return 0;
}

