#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
map<string,int> p;
string tt[6]={"","S","M","L","XL","XXL"};
int main(){
	ios::sync_with_stdio(false);
	int a[6];
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
	int k;
	cin >> k;
	p["S"] = 1;
	p["M"] = 2;
	p["L"] = 3;
	p["XL"] = 4;
	p["XXL"] = 5;
	string s;
	for(int i = 1;i <= k;++i){
		cin >> s;
		int t = p[s];
		for(int i = 0;i<=4;++i){
			if(t+i<=5&&a[t+i]){
				a[t+i]--;
				cout << tt[t+i] << endl;
				break;
			}
			else if(t-i>=1&&a[t-i]){
				a[t-i]--;
				cout << tt[t-i] << endl;
				break;
			}
		}
	}
	return 0;
}

