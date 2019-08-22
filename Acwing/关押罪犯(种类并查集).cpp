#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int f[2*maxn],size[2*maxn];
int _find(int x){
	if(f[x]==x)return x;
	return f[x] = _find(f[x]);
}
void _union(int x,int y){
	int hx = _find(x),hy = _find(y);
	if(hx==hy)return;
	if(size[hx]>=size[hy])f[hy] = hx,size[hx]+=size[hy];
	else f[hx] = hy,size[hy]+=size[hx];	
}
struct t {
	int a,b,c;
};
struct t tt[100005];
bool cmp(t t1,t t2){
	return t1.c>t2.c;
}

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int a,b;
	for(int i = 1;i<=2*n;++i)f[i] = i,size[i] =1;
	for(int i = 1;i<=m;++i){
	cin >> tt[i].a >> tt[i].b >> tt[i].c;	
	}
	sort(tt+1,tt+1+m,cmp);
	int flag = 0;
	for(int i = 1;i<=m;++i){
		int hx = _find(tt[i].a),hy = _find(tt[i].b);
		int hxx = _find(tt[i].a+n),hyy = _find(tt[i].b+n);
		//cout << hx << ' ' << hy << endl;
		if(hx==hy||hyy==hxx){
			cout << tt[i].c ;
			flag = 1;
			return 0;
		}
		else{
			//_union(tt[i].a,f[tt[i].a]);
			_union(tt[i].b,tt[i].a+n);
			_union(tt[i].a,tt[i].b+n);
		}
	}
	if(flag == 0)cout << 0;
	return 0;
}
