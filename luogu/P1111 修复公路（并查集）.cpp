#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
struct edge{
	int x,y,t;
};
int head[maxn],size[maxn];
int cnt;
int find(int x){
	if(head[x]==x)return x;
	return head[x] = find(head[x]);
}
void _union(int x,int y){
	int hx = find(x),hy =find(y);
	if(hx==hy)return;
	if(head[hx]==hx)cnt--;
	head[hx] = hy;
	size[hy]+=size[hx];
	
}
bool cmp(edge a,edge b){
	return a.t<b.t;
}

int main(){
	ios::sync_with_stdio(false);
	int n,m,l = 1e9,r = 0;
	cin >> n >> m;
	cnt  =n;
	struct edge e[m];
	for(int i = 1;i<=n;++i)head[i] = i,size[i] = 1;
	for(int i = 0;i<m;++i){
		cin >> e[i].x >> e[i].y >> e[i].t;
	}
	int flag = 0 ;
	sort(e,e+m,cmp);
	int ans = 1e6;
	for(int i = 0;i<m;++i){
		_union(e[i].x,e[i].y);
		if(cnt==1)ans = min(ans,e[i].t); 
	}
	if(ans==1e6){
		cout << -1 ;
	}
	else cout << ans;
	//cout << endl << cnt << endl;
	return 0;
}
