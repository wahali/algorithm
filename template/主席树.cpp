#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 +5 ;
struct seg{
	int ls,rs,dat;
}tr[maxn];
int tot =0,root[maxn];
int a[maxn],b[maxn],c[maxn];
int n;
void discrete(){  //a保存原数组,b为排序后的数组中间使用，c数组表示离散后的数组 
	for(int i = 1;i<=n;++i)b[i] = a[i];
	sort(b+1,b+1+n);
	int size = unique(b+1,b+1+n)-b-1;
	for(int i = 1;i<=n;++i)c[i] = lower_bound(b+1,b+1+size,a[i])-b;
}


int build(int l,int r){
	int p = ++tot;
	if(l==r){
		tr[p].dat = a[l];
		return p;
	}
	int m = (l+r)>>1;
	tr[p].ls = build(l,m);
	tr[p].rs  = build(m+1,r);
	tr[p].dat = max(tr[tr[p].ls].dat,tr[tr[p].rs].dat);
	return p;
}

int _insert(int now,int l,int r,int x,int val){
	int p = ++tot;
	tr[p] = tr[now];
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i<=n;++i)a[i] = n-i;
	discrete();
	//for(int i = 1;i<=n;++i)cout << a[i] << " "; 
	for(int i = 1;i<=n;++i)cout << c[i] << " "; 
	return 0;
}
