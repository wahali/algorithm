#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int n,k,cnt = 0;
	while(t--){
		cin >> n >> k;
		cnt = 0;
		for(int i = 1;i <= n;++i){
			cnt ++;
			if(cnt ==k+1)cnt = 1;
			cout << char('a' + cnt - 1);
			
		}
		cout << endl;
	}
	return 0;
}
