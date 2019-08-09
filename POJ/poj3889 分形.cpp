#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e6 +5 ;
#define  mk(m,n) make_pair(m,n)
ll mp(ll a, ll b){
	ll ans =1,tem = a;
	while(b){
		if(b&1)ans*=tem;
		tem *= tem;
		b >>= 1;
	}
	return ans;
}
inline double round( double d )
{
return floor( d + 0.5 );
}

pair<ll,ll> digui(ll n,ll m){
	//if(n==0) return make_pair(0,0);
	if(n==1){
		if(m==0)return mk(0,0);
		else if(m==1)return mk(0,1);
		else if(m==2)return mk(1,1);
		return mk(1,0);
	}
	else{
		ll t = mp(2,2*n-2);
		pair<ll,ll> a = digui(n-1,m%t);
		int len = mp(2,n-1);
		if(m/t==0)return mk(a.second,a.first);
		else if(m/t==1)return mk(a.first,a.second+len);
		else if(m/t==2)return mk(a.first+len,a.second+len);
		else return mk(2*len-1-a.second,len-1-a.first);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,x,y;
		cin >> n >> x >> y;
		//x--;y--;
		pair<ll,ll> a = digui(n,x-1);
		pair<ll,ll> b = digui(n,y-1);
		cout << round(10*sqrt(1.0*(a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second))) << endl;
		
	}
	return 0;
}
