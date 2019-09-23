#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
char mp[15][15][15];
int vis[15][15][15];
int hh,n,m;
bool is_ri(int h,int x,int y){
	if(h > hh || h <= 0 || x > n || x<=0||y > m||y <=0)return false;
	else return true;
}
int blo[10000],tot;
int a[6]={0,0 ,0,0 ,1,-1};
int b[6]={0,0 ,1,-1,0, 0};
int c[6]={1,-1,0,0 ,0, 0};
void dfs(int h,int x,int y,int co){
	vis[h][x][y] = co;
	blo[co]++;
	for(int i = 0;i < 6;++i){
		if(is_ri(h + a[i],x+b[i],y+c[i])){
			if(mp[h+a[i]][x+b[i]][y+c[i]]=='.'&&!vis[h+a[i]][x+b[i]][y+c[i]])dfs(h+a[i],x+b[i],y+c[i],co);
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin >> hh >> n >> m;
	int sx,sy;
	for(int i = 1;i <= hh;++i){
		for(int j = 1;j <= n;++j){
			for(int k = 1;k <= m;++k){
				cin >> mp[i][j][k];
			}
		}
	}
	//cout << "gafsdgdf" << endl;
	cin >> sx >> sy;
	tot = 1;
	for(int i = 1;i <= hh;++i){
		for(int j = 1;j <= n;++j){
			for(int k = 1;k <= m;++k){
				if(mp[i][j][k] == '.' &&!vis[i][j][k]){
					dfs(i,j,k,tot);
					tot ++;
				}
			}
		}
	}
	ll ans = blo[vis[1][sx][sy]];
	cout << ans;
	return 0;
}

