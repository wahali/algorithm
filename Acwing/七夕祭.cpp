#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int h[maxn],l[maxn];


int main(){
	ios::sync_with_stdio(false);
	int n,m,t,x,y;
	cin >> n >> m >> t;
	for(int i = 0;i<t;++i){
		cin >> x >> y;
		h[x] ++; l[y] ++;
	}
	int flag = 0;
	if(t%n==0 && t%m == 0)flag = 1;
	else if(t%n==0)flag = 2;
	else if(t%m==0)flag = 3;
	else flag = 4;
	for(int i = 1;i<=n;++i)h[i] -= (t / n); 
	for(int i = 1;i<=n;++i)h[i] += h[i-1];
	for(int i = 1;i<=m;++i)l[i] -= (t / m);
	for(int i = 1;i<=m;++i)l[i] += l[i-1];
	//for(int i =  1;i<=n;++i)cout << h[i] << endl;
	ll ans =0,tem;
	if(flag == 1){
		ans = 0;
		sort(h+1,h+n+1);
		tem = h[(n+1)/2];
		for(int i = 1;i<=n;++i)ans += abs(h[i]-tem);
		sort(l + 1,l + 1 + m);
		tem = l[(m+1)/2];
		for(int i = 1;i<=m;++i)ans+= abs(l[i]- tem);
		cout << "both " << ans << endl;
	}
	else if(flag == 2){
		ans = 0;
		sort(h+1,h+n+1);
		tem = h[(n+1)/2];
		//for(int i = 1;i<=n;++i)cout << h[i] << endl;
		for(int i = 1;i<=n;++i)ans += abs(h[i]-tem);
		cout << "row " << ans ;
	}
	else if(flag == 3){
		ans = 0;
		sort(l + 1,l + 1 + m);
		tem = l[(m+1)/2];
		//cout << tem << endl;
		//for(int i = 1;i<=m;++i)cout << l[i] << endl;
		for(int i = 1;i <= m;++i)ans+= abs(l[i]- tem);
		cout << "column " << ans ;
	}
	else {
		cout << "impossible";
	}
	return 0;
}
