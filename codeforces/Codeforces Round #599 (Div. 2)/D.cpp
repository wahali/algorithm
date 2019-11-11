#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
set<int> e[maxn];
set<int> p;
set<int> :: iterator it;
int vis[maxn];
queue<int> q;
void bfs(int x){
	q.push(x);
	p.erase(x);
	vis[x] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(it = p.begin();it!=p.end();){
			int v = *it++;
			if(!e[v].count(u)){
				p.erase(v);
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}
int main() {
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;++i){
		scanf("%d%d",&x,&y);
		e[x].insert(y);e[y].insert(x);
	}
	int cnt = 0;
	for(int i = 1;i <= n;++i)p.insert(i);
	for(int i = 1;i <= n;++i){
		if(!vis[i]){
			cnt ++;
			bfs(i);
		}
	}
	//cout << cnt - 1;
	printf("%d\n",cnt-1);
	return 0;
}

