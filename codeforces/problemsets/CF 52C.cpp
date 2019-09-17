#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
ll seg[4*maxn],a[maxn],MIN[4*maxn],lazy[4*maxn];
void push_up(int p){
	MIN[p] = min(MIN[2*p],MIN[2*p+1]);
}
void push_down(int p){
	if(lazy[p]){
	MIN[2*p] += lazy[p];
	MIN[2*p+1] +=lazy[p];
	lazy[2*p] += lazy[p];
	lazy[2*p+1] += lazy[p];
	lazy[p] = 0;
	}
}
void build(int l,int r,int p){
	if(l==r){
		//seg[p] = a[l];
		MIN[p] = a[l];
		//push_up(p/2);
		return;
	}
	MIN[p] = 9e18;
	int mid = (l + r) >> 1;
	build(l,mid,2*p);
	build(mid + 1,r,2*p+1);
	push_up(p);
}

void upd(int l,int r,int fl,int fr,int v,int p){
	if(l>=fl&&r<=fr){
		MIN[p] += v;
		//push_down(p);
		lazy[p] += v;
		//push_down(p);
		return;
	}
	int mid = (l + r) >> 1;
	push_down(p);
	if(mid<fr)upd(mid+1,r,fl,fr,v,2*p+1);
	if(mid>=fl)upd(l,mid,fl,fr,v,2*p);
	push_up(p);
}
ll query(int l,int r,int fl,int fr,int p){
	ll MM = 9e18;
	if(l >=fl&&r <= fr){
		//push_down(p);
		return  MIN[p];
	}
	int mid = (l + r ) >> 1;
	push_down(p);
	if(mid<fr)MM = min(MM,query(mid+1,r,fl,fr,2*p+1));
	if(mid>=fl)MM = min(MM,query(l,mid,fl,fr,2*p));
	return MM;
}

int main(){
	//ios::sync_with_stdio(false);
	int n,m;
	//cin >> n;
	scanf("%d",&n);
	for(int i = 1;i <= n ;++i)cin >> a[i];
	//cin >> m;
	scanf("%d",&m);
	ll l,r,tem;
	char ch;
	build(1,n,1);
	for(int i = 1;i <= m;++i){
		//cin >> l >> r;
		scanf("%lld %lld",&l,&r);
		ch = getchar();
		if(ch == '\n'){
			//printf("gdssdg\n");
			if(l > r)printf("%lld\n",min(query(1,n,l+1,n,1),query(1,n,1,r+1,1)));
			else printf("%lld\n",query(1,n,l+1,r+1,1));
		}
		else {
			//cin >>tem;
			scanf("%lld",&tem);
			if(l > r)upd(1,n,l+1,n,tem,1),upd(1,n,1,r+1,tem,1);
			else upd(1,n,l+1,r+1,tem,1);
			}
	}
	return 0;
}

