#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n,m;
int nx[2*maxn],head[maxn],ver[maxn*2],tot = 0,val[maxn],edge[2*maxn];
void add(int x,int y,int z){
	ver[++tot] = y;edge[tot] = z;
	nx[tot] = head[x];head[x] = tot;
}
bool dfs(int x,int color,int limit){
	//if(flag == 1)return;
	val[x] = color;
	for(int i = head[x];i;i = nx[i]){
		int y = ver[i];
		if(edge[i]<=limit)continue;
		if(!val[y]) {
			if(!dfs(y,3-color,limit))return false;
		}
		else if(val[y]==color)return false;
	}
	return true;
}

bool check(int limit){
	memset(val,0,sizeof(val));
	for(int i = 1;i<=n;++i){
		if(!val[i])if(!dfs(i,1,limit))return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	//int MIN = 2e9,MAX = 0;
	int a,b,c;
	cin >> n >> m;
	for(int i =1;i<=m;++i){
		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}
	int l = 0,r = 1e9,mid;
	while(l<r){ 
		mid = (l+r)>>1;
		if(check(mid))r = mid;
		else l = mid+1;
		//cout << mid << endl;
	}
	cout << l;
	return 0;
}
