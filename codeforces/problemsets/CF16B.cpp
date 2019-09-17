#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
struct P{
	int a,b;
}p[25];
bool cmp(P m,P n){
	return m.b >n.b;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= m;++i){
		cin >> p[i].a >> p[i].b;
	}
	sort(p+1,p+1+m,cmp);
	ll ans = 0;
	for(int i = 1;i <= m;++i){
		if(p[i].a >= n){
			ans += n * p[i].b;
			n = 0;
			break;
		}
		else {
			ans += p[i].a * p[i].b;
			n -= p[i].a;
		}
	}
	cout << ans ;
	return 0;
}

