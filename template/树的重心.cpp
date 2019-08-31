#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int nx[maxn],ver[maxn]head[maxn],tot;
int n,root;   //树上结点总数 ,重心位置 
void add(int x,int y){
	ver[++tot] = y;
	nx[tot] = head[x];head[x] = tot;
}
bool vis[maxn];
int size[maxn]; 
void dfs(int x){
	vis[x] = 1;size[x] = 1;
	int max_part = 0;
	for(int i = head[x];i;i = edge[i].nx){
		int y = edge[i].to;
		if(!vis[y])dfs(y);
		size[x] += size[y];
		max_part = max(max_part,size[y]);
	}
	max_part = max(max_part,n - size[x]);
	if(max_part < ans){
		ans = max_part;
		pos = x;
	}
} 

int main(){
	ios::sync_with_stdio(false);
	
	return 0;
}

