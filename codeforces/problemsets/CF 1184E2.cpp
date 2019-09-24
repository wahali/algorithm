#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
struct Edge{
	int x,y,val;
	int used,id;
}edge[maxn];
int fa[maxn],head[maxn],ver[3*maxn],nx[3*maxn],wei[3*maxn],tot;
int root,dep[maxn],rt[maxn][20],dis[maxn],mx[maxn][20];
ll ans[maxn];
void add(int x,int y,int z){
	ver[++tot] = y;wei[tot] = z;
	nx[tot] = head[x];head[x] = tot;
}
int _find(int x){
	if(x == fa[x])return x;
	return fa[x] = _find(fa[x]); 
}

bool cmp(Edge a,Edge b){
	return a.val < b.val;
}
void dfs(int x){
	for(int i = head[x];i;i = nx[i]){
		int y = ver[i];
		if(dep[y])continue;
		dep[y] = dep[x] + 1;
		dis[y] = dis[x] + wei[i];
		rt[y][0] = x;
		mx[y][0] = wei[i];
		dfs(y);
	}
}
int lca(int u,int v){
	if(dep[u] > dep[v])swap(u,v);
	
	for(int i = 19;i >= 0;--i){
		if(dep[rt[v][i]] >= dep[u])v = rt[v][i];
	}
	/*
	for(int i = 0;i < 20;++i){
		if((dep[v] - dep[u]) & (1 << i))v = rt[v][i];
	}
	*/
	if(u == v)return u;
	for(int i = 19;i >= 0;--i)
		if(rt[u][i]!=rt[v][i])u = rt[u][i],v = rt[v][i];
	return rt[u][0];
}

void lca_init(int n,int root){
	dfs(root);
	for(int j = 1;j < 20;++j){
		for(int i = 1;i <= n;++i){
			rt[i][j] = rt[rt[i][j-1]][j-1];
			mx[i][j] = max(mx[i][j-1],mx[rt[i][j-1]][j-1]);
		}
	}
}
int ask(int u,int cha){
	int res = 0;
	for(int i = 0;i < 20;++i)
		if(cha & (1 << i))res = max(res,mx[u][i]),u = rt[u][i];
	return res;
}
int query(int x,int y)
{
	int w = lca(x,y);
	int res = 0;
	res = max(ask(x,abs(dep[x]-dep[w])),ask(y,abs(dep[y]-dep[w])));
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= m;++i)cin >> edge[i].x >> edge[i].y >> edge[i].val,edge[i].id = i;
	for(int i = 1;i <= n;++i)fa[i] = i;
	int cnt = 1;
	sort(edge + 1,edge + 1 + m,cmp);
	tot =0;
	for(int i = 1;i <= m;++i){
		int hx = _find(edge[i].x),hy = _find(edge[i].y);
		if(hx == hy)continue;
		else {
			fa[hx] = hy;
			add(hx,hy,edge[i].val);
			add(hy,hx,edge[i].val);
			edge[i].used = 1;
			ans[edge[i].id] = -1;
		}
	}
	root = 1;
	dep[1] = 1;
	dis[1] = 0;
	lca_init(n,root);
	for(int i = 1;i <= m;++i){
		if(!edge[i].used){
			ans[edge[i].id] = query(edge[i].x,edge[i].y);
		}
	}
	for(int i = 1;i <= m;++i){
		if(ans[i]!=-1)cout << ans[i] << endl;
	}
	return 0;
}
