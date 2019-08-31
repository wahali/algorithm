#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'

struct Edge{
int to,nx;	
}edge[maxn];
int tot,head[maxn];

void init(){tot = 0;}
void add(int u,int v){
	edge[++tot].to = v;edge[tot].nx = head[u];
	head[u] = tot;
}
int linker[maxn],used[maxn];
int un;
bool dfs(int u){
	for(int i = head[u];i;i = edge[i].nx){
		int y = edge[i].to;
		if(!used[y]){
			used[y] = true;
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
	for(int i = 1;i<=un;++i){
		memset(used,0,sizeof(used));
		if(dfs(i))res++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	
	return 0;
}

