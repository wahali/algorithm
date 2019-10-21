#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
string s;
set<int> ss[26];
set<int> :: iterator it;
int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	int len = s.length();
	for(int i = 0;i < len;++i){
		ss[s[i]-'a'].insert(i+1);
	}
	int q;
	cin >> q;
	int ord,pos,l,r;
	char ch;
	while(q--){
		cin >> ord;
		if(ord == 1){
			cin >> pos >> ch;
			if(s[pos-1]!=ch)ss[s[pos-1]-'a'].erase(pos),ss[ch-'a'].insert(pos),s[pos-1] = ch;
		}
		else {
			cin >> l >> r;
			int cnt = 0;
			for(int i = 0;i < 26;++i){
				it = ss[i].lower_bound(l);
				if(it!=ss[i].end()&&*it<=r)cnt++;
			}
			cout << cnt << endl;
		}
	}

	return 0;
}

