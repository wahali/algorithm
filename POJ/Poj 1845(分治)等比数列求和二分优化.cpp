#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int mod = 9901;

ll qsm(ll a,ll b){
	ll ans = 1,tem = a;
	while(b){
		if(b&1)ans*=tem,ans %= mod;
		tem*=tem;
		tem %= mod;
		b >>= 1;
	}
	return ans%mod;
}

ll db(ll p,ll q){
	//cout << p << " " << q << endl;
	if(q==1)return (1+p)%mod;
	if(q==0)return 1;
	else if(q&1)return ((1+qsm(p,(q+1)/2))%mod*(db(p,(q-1)/2))%mod)%mod;
	else return  (((1+qsm(p,q/2))%mod*(db(p,q/2-1))%mod+mod)%mod+qsm(p,q)%mod)%mod;
}

int main(){
	ios::sync_with_stdio(false);
	ll a,b;
	cin >> a >> b;
	ll ans = 1;
	ll num;
	for(int i = 2;i*i<=a;++i){
		if(a%i==0){
		num = 0;
		while(a%i==0){
			num++;
			a/=i;
		}
		//cout << i << ' ' << num <<endl;
		ans *= db(i,num*b);
		ans%=mod;
	}
	}
	if(a>1){
		//cout << a << endl;
		ans*=db(a,b)%mod;
	}
	ans %= mod;
	cout << ans ;
	return 0;
}
