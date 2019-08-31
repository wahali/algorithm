#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
int a[maxn],b[maxn];


int main(){
	ios::sync_with_stdio(false);
	int n;
	ll ans;
	while(cin >> n){
		if(n==0)break;
		ans = 0;
		
		for(int i = 1 ;i <= n; ++i)cin >> a[i];
		for(int i = 1 ;i <= n; ++i) cin >> b[i];
		sort(a + 1,a + 1 + n);
		sort(b + 1,b + 1 + n);
		int la = 1,ra = n,lb = 1,rb = n;
		int cnt = 0;
		while(1){
			if(a[ra]>b[rb]){
			ra--;rb--;
			ans+=200;
			}
			else if(a[ra]<b[rb]){
				ans-=200;
				la++;
				rb--;
			}
			else{
				if(a[la] > b[lb]) {
					la++;
					lb++;
					ans += 200;
				}
				else{
					if(a[la]<b[rb])ans -= 200;
					la++;
					rb--;
					
				}
			}
			cnt++;
			if(cnt==n)break;
		}
		cout << ans << endl;
	}
	return 0;
}
