#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e5+5;
int m[7][7],t[7][7],MIN;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n--){
		MIN = 1e9;
	char ch;
	for(int i = 1;i<=5;++i)
		for(int j = 1;j<=5;++j)
			cin >> ch,m[i][j] = ch-'0';
	for(int i = 0;i<(1<<5);++i){
		for(int j = 1;j<=5;++j)
			for(int k = 1;k<=5;++k)
				t[j][k] = m[j][k];
		int ans = 0;
		for(int j = 0;j<5;++j){
			if(i>>j&1){
				ans ++;
				t[1][j+1] ^=1;
				t[1][j+2] ^= 1;
				t[1][j] ^= 1;
				t[2][j+1] ^= 1;
				
			}
		}
		for(int j = 1;j<=4;++j){
			for(int k = 1;k<=5;++k){
				if(!t[j][k]){
					ans ++;
					t[j][k] ^=1;
					t[j+1][k] ^= 1;
					t[j+1][k+1] ^= 1;
					t[j+1][k-1] ^= 1;
					t[j+2][k] ^= 1;
				}
			}
		}
		int flag = 0;
		for(int j = 1;j<=5;++j){
			for(int k = 1;k<=5;++k)
			if(!t[j][k]){
				flag = 1;
				break;
			}
		}
		//cout << flag << " " << ans << endl;
		if(!flag&&ans<=6){
			MIN = min (MIN,ans);
		}
	}
	if(MIN == 1e9)cout << -1 << endl;
	else cout << MIN << endl;
	}
	return 0;
}
