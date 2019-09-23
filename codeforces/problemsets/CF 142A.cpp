#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll MAX = 0,MIN = 9e18;
	for(ll i = 1;i*i*i <= n;++i){
		if(n%i==0){
			for(ll j = i;j*j<=n/i;++j){
			if((n/i)%j!=0)continue;
			ll k = n/i/j;
			MAX = max(MAX,(i+1)*(j+2)*(k+2)-i*j*k);
			MAX = max(MAX,(j+1)*(i+2)*(k+2)-i*j*k);
			MAX = max(MAX,(k+1)*(j+2)*(i+2)-i*j*k);
			MIN = min(MIN,(i+1)*(j+2)*(k+2)-i*j*k);
			MIN = min(MIN,(j+1)*(i+2)*(k+2)-i*j*k);
			MIN = min(MIN,(k+1)*(j+2)*(i+2)-i*j*k);
		}
	}
		
}
cout << MIN << " " << MAX ;
	return 0;
}

