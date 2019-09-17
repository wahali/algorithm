#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'

int main(){
	ios::sync_with_stdio(false);
	ll n;
	double k;
	cin >> n >> k;
	double sum = 0;;
	ll num = n;
	ll tem;
	for(int i = 1;i <= n;++i){
		cin >> tem;
		sum += tem;
	}
	ll tt = (ll)2 * (n*k-sum) - n;
	
	tt = max((ll)0,tt);;
	//cout << (ll)2 * (n*k-sum) - n << endl;
	while(sum + tt*k < (k-0.5)* (n + tt)){
		sum += k;
		tt ++;
	}
	cout << tt<< endl;
	
	return 0;
}

