#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int h[maxn],l[maxn],hs[maxn],ls[maxn];

int main(){
	ios::sync_with_stdio(false);
	int hn =0,ln = 0;
	int t;
	cin >> t;
	string s;
	int hu,hd,lu,ld,hmax,hmaxp,hmin,hminp,lmax,lmaxp,lmin,lminp,hmaxpp,hminpp,lmaxpp,lminpp;
	while(t--){
		hn = 0,ln = 0;
		hu = hd = lu = ld =0;
		hs[0] = 0,ls[0] = 0;
		hmax = 0;hmin = 0;lmax = 0,lmin = 0;
		hmaxp = hmaxpp = hminp = hminpp = lmaxp = lmaxpp = lminp = lminpp = 1;
		cin >> s;
		for(int i = 0;i<s.length();++i){
			if(s[i]=='D')h[++hn] = 1;
			else if(s[i]=='A')h[++hn] = -1;
			else if(s[i]=='W')l[++ln] = 1;
			else if(s[i]=='S')l[++ln] = -1;
		}
		for(int i = 1;i<=hn;++i){
			hs[i] = hs[i-1] + h[i];
			//cout << hs[i] << ' ';
			if(hs[i]>=hmax){
				if(hs[i]>hmax)hmaxpp = i;  //��һ����� 
				hmax = hs[i];
				hmaxp = i;     //���һ����� 
			}
			if(hs[i]<=hmin){
			if(hs[i]<hmin)hminp = i; //��һ��С�� 
				hmin = min(hmin,hs[i]);   
				hminpp = i; 		//���һ��С�� 
			}
		}
		//cout << endl;
		//cout << hmaxp << ' ' << hminp << endl;
		if(hmaxp<hminp)hd = 1;
		if(hminpp<hmaxpp)hu =1;
		for(int i = 1;i<=ln;++i){
			ls[i] = ls[i-1]+l[i];
			//cout << ls[i] <<  ' ';
			if(ls[i]>=lmax){
			if(ls[i]>lmax)lmaxpp = i;      //��һ�����; 
				lmax = ls[i];
				lmaxp = i;        //���һ����� 
				
			}
			if(ls[i]<=lmin){
			if(ls[i]<lmin)lminpp = i;  //��һ��С�� 
				lmin = ls[i];
				lminp = i;       //���һ��С�� 
				
			}
		}
		//cout << endl;
		//cout << hmax << ' ' << hmin << ' ' << lmax << ' ' << lmin << endl;
		if(lmaxp<lminpp)ld = 1;
		if(lminp<lmaxpp)lu = 1;
		ll ans = (ll)(lmax-lmin+1)*(hmax-hmin+1);
		//cout << ans << endl;
		//cout << hu << ' ' << hd << ' ' << lu << ' ' << ld << endl;
		if(hu||hd&&hn>=2)ans = min(ans,(ll)(lmax-lmin+1)*(hmax-hmin));
		if(lu||ld&&ln>=2)ans = min(ans,(ll)(lmax-lmin)*(hmax-hmin+1));
		cout << ans << endl;
	}
	return 0;
}
