#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn  = 1e6 +5;
const ll mod = 19930726;
ll chen[maxn];
char Ma[maxn*2];
int Mp[maxn*2];
char s[maxn];
map<ll,ll> p;
ll ksm(ll a,ll b){
	ll ans = 1,tem = a;
	while(b){
		if(b&1){
			ans = (ans * tem) % mod;
			
	}
	tem  =(tem * tem) % mod;
			b >>= 1;
	}
	return ans;
}
void Manacher(char s[],int len){
	int l = 0;
	Ma[l++] = '$';
	Ma[l++] = '#';
	for(int i = 0;i < len;++i){
		Ma[l++] = s[i];
		Ma[l++] = '#';
	}
	//Mp[l] = 0;
	int mx = 0,id = 0;
	for(int i = 0;i < l ;++i){
		Mp[i] = mx >  i ? min(Mp[2 * id - i],mx -  i) : 1;
		while(Ma[i + Mp[i]] == Ma[i - Mp[i]])Mp[i] ++;
		if(i + Mp[i] > mx ){
			mx = i + Mp[i];
			id = i;
		}
	}
	for(int i = 0 ;i<l;++i){
		//cout << i << " " << Mp[i] - 1 << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	ll n,k;
	cin >> n >> k;
	for(int i = 0 ;i < n;++ i){
		cin >> s[i];
	}
	Manacher(s,n);
	ll num = 0;
	for(int i = 0;i<n;++i){
		//cout << i << " " << Mp[2*i+2] << endl;
		num += Mp[2*i+2]/2;
		p[Mp[2*i+2]-1]++;
		//cout << Mp[2*i+2]-1 << " " << p[Mp[2*i+2]-1] << endl;
	}
	//cout << num << endl;
	if(num < k){
		cout << -1 << endl;
		return 0;
	}
	ll ans = 1;
	for(int i = n;i>0;--i){
		if(k==0)break;
		if(p[i]){
			if(p[i] <= k){
				p[i-2] += p[i];
				k -= p[i];
				ans = (ans * ksm(i,p[i])) % mod;
			}
			else {
				ans = (ans * ksm(i,k)) % mod;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
