#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2+5;
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = s.length()-1;i>=0;--i){
		if(!cnt&&s[i]=='1')s[i] ='0';
		else if(s[i]=='0')cnt++;
		else cnt--;
	}
	cout << s << endl;
	return 0;
}
