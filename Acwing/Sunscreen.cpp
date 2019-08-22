#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int cov[maxn],f[maxn];
struct t{
	int MIN,MAX;
};
struct m{
	int sp,cov;
};
bool cmp(t a,t b){
	if(a.MIN>b.MIN)return true;
	else if(a.MIN==b.MIN&&a.MAX > b.MAX) return true;
	else return false;
}
bool cmpmm(m a,m b){
	return a.sp>b.sp;
}

int main(){
	ios::sync_with_stdio(false);
	int c,l;
	cin >> c >> l;
	struct t tt[c+1];
	struct m mm[l+1];
	for(int i = 1;i<=c;++i){
		cin >> tt[i].MIN >> tt[i].MAX;
	}
	for(int i = 1;i<=l;++i){
		cin >> mm[i].sp >> mm[i].cov;
	}
	sort(tt+1,tt+1+c,cmp);
	sort(mm+1,mm+1+l,cmpmm);
	int ans = 0;
	for(int i = 1;i<=c;++i){
		for(int j = 1;j<=l;++j){
			if(mm[j].cov>0){
				if(mm[j].sp>=tt[i].MIN&&mm[j].sp<=tt[i].MAX){
					mm[j].cov--;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans ;
	return 0;
}
