#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
ll a[maxn],tem[maxn],b[maxn];

void merge(int l,int mid,int r){
	int ll =l,rr = mid+1,t = l;
	while(ll<=mid&&rr<=r){
		if(tem[ll]<=tem[rr])b[t++] = tem[ll++];
		else b[t++] = tem[rr++];
	}
	while(ll<=mid)b[t++] = tem[ll++];
	while(rr<=r)b[t++] = tem[rr++];
	//for(int i = l;i<=r;++i)b[i] = tem[i];
}

int main(){
	ios::sync_with_stdio(false);
	ll k,n,m,t;
	cin >> k;
	while(k--){
		cin >> n >> m >> t;
		for(int i = 1;i <= n;++i)cin >> a[i];
		int l = 0,r = 0,p = 1;
		int ans =0;
		while(r<=n){
			l = r+1;r = l,p = 1;
			tem[l] = a[l];
			while(p){
			for(int i = r+1;i <= r+p;++i)tem[i] = a[i];
			sort(tem+r+1,tem+r+p+1);
			merge(l,r,r+p);
			//for(int i = l;i <=r+p;++i)cout << b[i] << endl;
			//cout << endl;
			ll cnt = 0;
			for(int i = 1;i<=m&&i<=(r+p-l+1)/2;++i) cnt+= (b[r+p-i+1]-b[l+i-1])*(b[r+p-i+1]-b[l+i-1]);
			//cout << "cnt " <<cnt << endl;
			if(cnt > t){
					p /= 2;
					//cout << " gsdf" << endl;
			}
			else {
				r += p;
				for(int i = l;i<=r;++i)tem[i] = b[i];
				p = min(n-r,(ll)p<<1);
				//cout << "dsfhdsd " << p << endl;
			}
			if(r >= n)break;
		}
		//cout << r << endl;
		//cout << r << ' ' << ans << endl;
		ans ++;
		if(r>=n)break;
		}
	cout << ans << endl;
	}
	return 0;
}
