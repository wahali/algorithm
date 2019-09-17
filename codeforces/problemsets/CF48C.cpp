#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
double a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	double MIN,MAX;
	int tem;
	cin >> tem;
	MIN = tem,MAX = tem + 1;
	for(int i =2;i<=n;++i){
		cin >> tem;
		MIN = max(MIN,1.0*tem/i);
		MAX = min(MAX,1.0*(tem+1)/i);
	}
	MIN *=(n+1),MAX *=(n+1);
	int l = (int)floor(MIN),r = (int)floor(MAX);
	if(MAX == floor(MAX))r--;
	if(l==r){
		cout << "unique" << endl;
		cout << l;
	}
	else cout << "not unique";
	return 0;
}

