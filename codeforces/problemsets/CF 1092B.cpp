#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int a[105];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum =0,ans = 0,tem;
	for(int i = 1;i <= n;++i)cin >> tem,a[tem]++;
	for(int i = 1;i <= 100;++i){
		if(a[i]%2==0)a[i] = 0;
		else a[i] = 1;
	}
	int cnt =0;
	for(int i = 1;i <= 100;++i){
		if(a[i]){
			if(cnt ==0){
			cnt = 1;
			ans -= i;
		}
		else{
			ans +=i;
			cnt = 0;
		}
		}
	}
	cout << ans;
	return 0;
}
