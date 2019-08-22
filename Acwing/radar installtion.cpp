#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
struct t{
	double l,r;
};
bool cmp(t a,t b){
	if(a.l<b.l)return true;
	else if(a.l==b.l){
		if(a.r>=b.r)return true;
		else return false;
	}
	else return false;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	double d;
	cin >> n >> d;
	double x,y;
	struct t tt[n+1];
	int flag  = 0;
	for(int i = 1;i<=n;++i){
		cin >> x >> y; 
		if(y>d)flag= 1;
		tt[i].l = x-sqrt(d*d-y*y);
		tt[i].r = x+sqrt(d*d-y*y);
	}
	if(flag == 1){
		cout <<  -1 ;
		return 0;
	}
	sort(tt+1,tt+1+n,cmp);
	double tem;
	tem = tt[1].r;
	int cnt = 1;
	for(int i = 2;i<=n;++i){
		if(tt[i].l<=tem){
			tem = min(tem,tt[i].r);
		}
		else{
			cnt ++;
			tem = tt[i].r;
		}
	}
	cout << cnt << endl;
	return 0;
}
