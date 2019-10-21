#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		a -= b;
		if(a!=1)cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}

