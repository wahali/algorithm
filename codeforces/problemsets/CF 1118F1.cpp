#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
int ver[2*maxn],nx[2*maxn],head[maxn],tot;
int a[maxn];
int r[maxn],b[maxn];
void add(int x,int y){
	ver[++tot] = y;
	nx[tot] = head[x];head[x] = tot;
}
int vis[maxn];
int bb,rr;
ll ans = 0;
void dfs(int now){
	vis[now] = 1;
	r[now] = b[now] = 0;
	if(a[now]==1)b[now]++;
	else if(a[now]==2)r[now]++;
	for(int i = head[now];i;i = nx[i]){
		int y = ver[i];
		if(vis[y])continue;
		dfs(y);
		r[now]+=r[y];
		b[now]+=b[y];
		if((b[y]==bb&&r[y]==0)||(r[y]==rr&&b[y]==0)){
			ans++;
			//cout << now << " " << y <<" " << b[y] << ' ' << r[y]<< endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n,x,y;
	cin >> n;
	bb = rr = 0;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		if(a[i]==1)bb++;
		else if(a[i]==2)rr++;
	}
	for(int i = 1;i < n;++i){
		cin >> x >> y;
		add(x,y);add(y,x);
	}
	dfs(1);
	cout << ans;
	return 0;
}
