#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
struct E{
	int nx,to,val;
}e[maxn];
int tot,ct;
int cnt[maxn],son[maxn],top[maxn],sz[maxn],f[maxn],dep[maxn],head[maxn],dfn[maxn],seq[maxn],c[maxn],ans[maxn];
int mx,sum,hson;
void add(int x,int y){
	e[++tot].to = y;
	e[tot].nx = head[x];
	head[x] = tot;
}
void dfs1(int u,int fa,int dpt){   //初始化dep，子树sz，重儿子，父节点 
	f[u] = fa;sz[u] = 1;dep[u] = dpt;
	for(int i = head[u];i;i = e[i].nx){
		int v = e[i].to;
		if(v == fa)continue;
		dfs1(v,u,dpt+1);
		sz[u]+=sz[v];
		if(sz[v] > sz[son[u]])son[u] = v; //更新重儿子 
	} 
}
void dfs2(int u,int t){      //初始化所在链最顶端的点，dfs序，新序列； 
	top[u] = t;
	dfn[u] = ++ ct;seq[ct] = c[u];
	if(!son[u])return;
	dfs2(son[u],t);
	for(int i = head[u];i;i = e[i].nx){
		int v = e[i].to;
		if(v!=son[u]&&v!=f[u])dfs2(v,v);
	}
} 
void cal(int now,int fa,int y){
	cnt[c[now]]+=y;
	if(cnt[c[now]]==mx)sum+=c[now];
	else if(cnt[c[now]]>mx)mx = cnt[c[now]],sum = c[now];
	for(int i = head[now];i;i = e[i].nx){
		int to = e[i].to;
		if(to!=fa&&to!=hson)cal(to,now,y);
	}
		
}
void ddfs2(int now,int fa,int keep){
	for(int i = head[now];i;i = e[i].nx){
		int to = e[i].to;
		if(to==fa||to==son[now])continue;
		ddfs2(to,now,0);
	}
	if(son[now])ddfs2(son[now],now,1);
	hson = son[now];
	cal(now,fa,1);
	hson = 1;
	ans[now] =  sum;
	if(!keep)cal(now,fa,-1),sum =  0,mx = 0;
}

int n,x,y;
int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;++i)scanf("%d",&c[i]);
	for(int i = 1;i < n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1,1,1);
	dfs2(1,1);
	ddfs2(1,1,0);
	for(int i = 1;i <= n;++i)printf("%d ",ans[i]);
	return 0;
}

