#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
map<double,int> p;
int a[maxn],vis[maxn];
int n;
bool check(double k,int p){
	memset(vis,0,sizeof(vis));
	int cnt = 0;
	for(int i = 1;i <= n;++i){
		if(a[i]-p==1ll*k*(i-1)){
			vis[i] = true;
			++cnt;
		}
	}
	if(cnt == n)return false;
	if(cnt == n-1 )return true;
	int pos1 = 0;
	for(int i = 1;i<=n;++i)
		if(!vis[i]&&pos1 ==0)pos1 = i;
	for(int i = pos1 + 1;i<=n;++i){
		if(!vis[i]){
			if(fabs((double)(a[i]-a[pos1])/(i-pos1)-k)>1e-7)return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1;i <= n;++i)cin >> a[i];
	int ans =0;
	ans |= check(1.0*(a[2]-a[1]),a[1]);
	ans |= check(0.5*(a[3]-a[1]),a[1]);
	ans |= check(1.0*(a[3]-a[2]),2*a[2]-a[3]);
	if(ans)cout << "YES";
	else cout << "NO";
	return 0;
}

