#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
ll num[105][105][15];
ll bri[105][105][15];
ll ans[105][105][15];
int main(){
	ios::sync_with_stdio(false);
	ll n,q,c,x,y,s,t,x2,y2;
	cin >> n >> q >> c;
	memset(bri,0,sizeof(bri));
	for(int i = 1;i <= n;++i){
		cin >> x >> y >> s; 
		num[x][y][s]++;
		bri[x][y][0] = s;
	}
	for(int i = 1;i <=100;++i){
		for(int j = 1;j <= 100;++j){	
			for(int k = 0;k<= c;++k){
				num[i][j][k]+=num[i][j-1][k]+num[i-1][j][k]-num[i-1][j-1][k];
			}
		}		
	}
	ll res;
	for(int i = 1;i <= q;++i){
		cin >> t  >> x >> y >> x2 >> y2;
		res = 0;
		for(int j = 0;j<=c;++j){
			res += (j+t)%(c+1)*(num[x2][y2][j]-num[x2][y-1][j]-num[x-1][y2][j]+num[x-1][y-1][j]);
		}
		cout << res << endl;
	}
	return 0;
}

