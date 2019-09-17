#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'

int main(){
	ios::sync_with_stdio(false);
	unsigned long long  a,b;
	cin >> a >> b;
	if((a-b)&1){
		cout << -1 ;
		return 0;
	}
	ll x,y;
	x = (a - b) / 2;
	y = x + b;
	cout << x << " " << y << endl;
	return 0;
}

