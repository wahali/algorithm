#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
ll a[maxn],tot;
int main() {
	ll n;
	//scanf("%lld",&n);
	cin >> n;
	if(n==1){
		cout << 1;
		return 0;
	}
	if(n%2==0){
		a[++tot] = 2;
		while(n%2==0)n/=2;
	}
	for(ll i = 3;i*i<=n;i+=2){
		if(n%i==0){
			a[++tot] = i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1)a[++tot] = n;
	if(tot>=2)cout << 1 << endl;
	else cout << a[1] << endl;
	return 0;
}

