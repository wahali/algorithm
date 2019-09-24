#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
set<string> s[105];
set<string> ::iterator it;

int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	string str;
	cin >> str;
	k--;
	int len = str.length();
	int cnt = 0;
	s[len].insert(str);
	int l = len;
	string tem;
	int num =0;
	while(cnt < k){
		if(l==0)break;
		for(it = s[l].begin();it!=s[l].end();it++){
			int lens = (*it).length();
			for(int j = 0;j<lens;++j){
				tem = *it;
				tem.erase(j,1);
				if(!s[l-1].count(tem))cnt++,num+=len-l+1;
				s[l-1].insert(tem);
				if(cnt == k)break;
			}
			if(cnt == k)break;
		}
		l--;
	}
	if(cnt <k)cout << -1 ;
	else cout << num << endl;
	return 0;
}
