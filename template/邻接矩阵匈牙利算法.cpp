#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
/*
ÁÚ½Ó¾ØÕóÊÊºÏÓÃÓÚ³íÃÜÍ¼ 
*/

int un,vn;
int g[maxn][maxn]; 
int linker[maxn];
bool used[maxn];
bool dfs(int u){
	for(int v = 0;v<vn;++v){
		if(g[u][v]&&!used[v]){
			used[v]  = true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary(){
	int res = 0;
	memset(linker,-1,sizeof(linker));
	for(int u = 0;u<un;++u){
		memset(used,-1,sizeof(used));
		if(dfs(u))res++;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);

	return 0;
}

