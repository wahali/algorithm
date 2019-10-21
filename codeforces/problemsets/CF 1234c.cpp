#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int a[maxn],b[maxn];
int main() {
	ios::sync_with_stdio(false);
	int q,n;
	cin >> q;
	while(q--){
		cin >> n;
		string s;
		cin >> s;
		for(int i = 1;i <= n;++i)a[i] = s[i-1]-'0';
		cin >> s;
		for(int i = 1;i <= n;++i)b[i] = s[i-1]-'0';
		//for(int i = 1;i <=n;++i)cout << b[i] << endl;
		int tag = 0,flag = 0;
		for(int i = 1;i<=n;++i){
			//cout << i << " " << tag << endl;
			if(tag==0){
				if(a[i]==1||a[i]==2)continue;
				if(a[i]>2&&b[i]>2)tag = 1;
				else {
					flag = 1;
					break;
				}
			}
			else{
				if(b[i]==1||b[i]==2)continue;
				if(a[i]>2&&b[i]>2)tag = 0;
				else {
					flag = 1;
					break;
				}
			}
		}
		//cout << flag << ' ' << tag << endl; 
		if(flag == 1)cout << "NO" << endl;
		else if(tag == 0)cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	return 0;
}

