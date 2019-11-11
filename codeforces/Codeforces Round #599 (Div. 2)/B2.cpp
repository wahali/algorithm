#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int num[27],tot;
pair<int,int> p[maxn];
int main() {
	ios :: sync_with_stdio(false);
	int t,n;
	string s1,s2;
	cin >> t;
	while(t--){
		tot = 0;
		cin >> n;
		cin >> s1 >> s2;
		for(int i = 0;i < n;++i){
			num[s1[i]-'a']++,num[s2[i]-'a']++;
		}
		int flag = 0;
		for(int i = 0;i < 26;++i){
			if(num[i]&1){
				flag = 1;
			}
			num[i] = 0;
		}
		if(flag == 1){
			cout << "No" << endl;
			continue;
		}
		
		for(int i = 0;i < n;++i){
			if(s1[i]!=s2[i]){
			flag = 0;
			for(int j = i+1;j<n;++j){
				if(s1[j]==s1[i]){
					p[++tot].first = j+1;
					p[tot].second = i+1;
					swap(s1[j],s2[i]);
					flag = 1;
					break;
				}
			}
			if(flag==0){
				for(int j = i+1;j<n;++j){
					if(s2[j]==s1[i]){
					p[++tot].first = j+1;
					p[tot].second = j+1;
					swap(s1[j],s2[j]);
					p[++tot].first = j+1;
					p[tot].second = i+1;
					swap(s2[i],s1[j]);
					flag = 1;
					break;
					}
				}
			}
		}
		}
		cout << "Yes" << endl;
		cout << tot << endl;
		for(int i = 1;i <= tot;++i){
			cout << p[i].first << ' ' << p[i].second <<  endl;
		}
	}
	
	
	
	return 0;
}

