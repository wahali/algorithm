#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int a[maxn],b[maxn],tot1,tot2;
int main() {
	int k,n;
	//scanf("%d",&k);
	string s1,s2;
	cin >> k;
	while(k--){
		//scanf("%d",&n);
		cin >> n;
		cin >> s1 >> s2;
		int num =0;
		tot1 = 0;tot2 = 0;
		for(int i = 0;i < n;++i){
			if(s1[i]!=s2[i]){
				num++;
				a[++tot1] = i;
			}
		}
		if(num!=2){
			cout << "NO" << endl;
		}
		else {
			swap(s1[a[1]],s2[a[2]]);
			//swap(s1[a[2]],s2[a[1]]);
			if(s1!=s2)cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	return 0;
}

