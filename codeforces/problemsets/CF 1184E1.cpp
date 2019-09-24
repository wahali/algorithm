#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
struct Edge{
	ll x,y,val;
}edge[maxn];
int n,m;
ll l = 0,r = 1e9 + 10,mid;
bool cmp(Edge a,Edge b){
	return a.val < b.val ;
}
int head[maxn];
int flag = 0;
int _find(int x){
	if(x == head[x])return x;
	else return head[x] = _find(head[x]);
}
void _union(int x,int y){
	int hx = _find(x),hy = _find(y);
	if(hx == hy)return;
	head[hx] = hy;
}


int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i =0;i < m;++i){
		cin >> edge[i].x >> edge[i].y >> edge[i].val;
	}
	sort(edge+1,edge+m,cmp);
	for(int i = 1;i <= m;++i)head[i] = i;
	for(int i = 1;i < m;++i){
		if(_find(edge[i].x)!=_find(edge[i].y)){
			head[_find(edge[i].x)] = _find(edge[i].y);
			if(_find(edge[0].x)==_find(edge[0].y)){
				cout << edge[i].val;
				return 0;
			}
		}
	}
	cout << 1000000000;
	return 0;
}

