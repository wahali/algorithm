#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
 
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	ll n;
	while(t--){
		cin >> n;
		int l = 1,r = 1e7,mid;
		while(l<r){
			mid = (l+r+1)>>1;
			if((ll)(mid-1)*(mid)/2<=n){
				l = mid;
			}
			else r = mid-1;
		}
		n-=(ll)l*(l-1)/2;
		cout << "133";
		for(int i = 0;i<n;++i)cout << '7';
		for(int i=0;i<l-2;++i)cout << '3';
		cout<< '7' << endl;
		}
	return 0;
}
