#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int head[maxn],ver[maxn],nx[maxn],tot,pre[maxn],vis[maxn];
void add(int x,int y){
	ver[++tot] = y;
	nx[tot] = head[x];head[x] = tot;
}
void dfs(int x){
	vis[x] = 1;
	for(int i = head[x];i;i = nx[i]){
		int y = ver[i];
		if(vis[y])continue;
		pre[y] = x;
		dfs(y);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n,r1,r2;
	cin >> n >> r1 >> r2;
	int tem;
	for(int i = 1;i <= n ;++i){
		if(i==r1)continue;
		cin >> tem;
		add(i,tem);
		add(tem,i);
	}
	dfs(r2);
	for(int i = 1;i <= n;++i){
		if(i!=r2)cout << pre[i] << ' ';
	}
	return 0;
}

