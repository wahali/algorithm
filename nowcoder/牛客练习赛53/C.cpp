#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
bitset<maxn>a[maxn],q,tag;
int main(){
	ios::sync_with_stdio(false);	
	int n,m;
	cin >> n >> m;
	string s;
	for(int i = 0;i < n; ++i){
		cin >> s;
		for(int j = 0;j < m;++j){
			a[i][j] = (s[j]=='1');
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		cin >> s;
		for(int i = 0;i<m;++i){
			if(s[i]=='_'){
				q[i] = 0;
				tag[i] = 0;
			}else{
				q[i] = 1;
				tag[i] = (s[i]=='1');
			}
		}
		int ans = 0;
		for(int i = 0;i<n;++i){
			if((a[i]&q)==tag)ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

