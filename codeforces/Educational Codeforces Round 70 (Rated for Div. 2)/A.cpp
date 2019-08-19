#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e5 + 5;
 
 
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s1,s2;
		cin >> s1;
		cin >> s2;
		int x1=0,x2=0;
		for(int i = s2.length()-1;i>=0;--i){
			if(s2[i]=='1'){
				x2 = s2.length()-i;
				break;
			}
		}
		for(int i = s1.length()-1;i>=0;--i){
			if(s1[i]=='1'&&s1.length()-i>=x2){
				x1 = s1.length()-i;
				break;
			}
		}
		if(x1!=0)cout << x1-x2 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
