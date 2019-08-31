#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+ 5;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int n,m;
int f[maxn][maxn],vis[maxn],used[maxn],cnt;
int linker[maxn],post[maxn];
bool  dfs(int x){
	for(int i = 0;i < n;++i){
		if(f[x][i] && used[i] != cnt){
			used[i] = cnt;
			if(linker[i] == -1 || dfs(linker[i])){
				linker[i] = x;
				post[x] = i;
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	int x,y;
	memset(linker,-1,sizeof(linker));
	cnt = 1;
	for(int i = 1;i <= m; ++ i){
		cin  >> x >> y;
		f[i][y] = 1,f[i][x] = 1;
	}
	int res = 0;
	for(int i = 1;i <= m; ++ i){
		if(dfs(i))res++;
		else break;
		cnt ++;
	}
	cout << res << endl;
	for(int i = 1;i <= res ;++i){
		cout << post[i] << endl;
	}
	return 0;
}
