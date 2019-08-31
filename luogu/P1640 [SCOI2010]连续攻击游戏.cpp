#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
inline bool max(ll a,ll b){
	return a>b?a:b;
}
struct Edge{
int to,nx;	
}edge[2*maxn];
int tot,head[10005];
void init(){tot = 0;}
void add(int u,int v){
	edge[++tot].to = v;edge[tot].nx = head[u];
	head[u] = tot;
}
int linker[maxn],used[maxn];
int un;
int cnt = 1;
bool dfs(int u){
	for(int i = head[u];i;i = edge[i].nx){
		int y = edge[i].to;
		if(used[y]!=cnt){
			used[y] = cnt;
			if(linker[y]==-1||dfs(linker[y])){
				linker[y] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary(){
	memset(linker,-1,sizeof(linker));
	int res = 0;
	for(int i = 1;i<=10000;++i){
		//memset(used,0,sizeof(used));
		if(dfs(i))res++;
		else break;
		cnt++;
		//else return res;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int e,l,r;
	//cin >> n >> m >> e;
	cin >> e;
	ll MAX = 0;
	int vn = 0;
	init();
	for(int i = 1;i<=e;++i){
		cin >> l >> r;
		if(l>r)swap(l,r);
		vn = max(vn,r);
		un = max(un,l);
		//MAX = max(MAX,r);
		//if(l>n||r>m)continue;
		add(l,i);
		add(r,i);
		//add(r,l);
	}
	//un = MAX;
	cout << hungary();
	
	return 0;
}

