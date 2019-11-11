#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int a[maxn];
stack<int> p;
bool cmp(int a,int b){
	return a > b;
}
int main() {
	int n,k;
	int l,num,ans;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)scanf("%d",&a[i]);
		ans = 0;
		sort(a+1,a+1+n,cmp);
		for(int i = 1;i <=n;++i){
			if(a[i]<i){
				ans = i-1;
				break;
			}
		}
		if(ans == 0)ans = a[n];
		printf("%d\n",ans);
	}
	return 0;
}

