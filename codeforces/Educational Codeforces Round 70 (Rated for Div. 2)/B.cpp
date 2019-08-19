#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int dp[10][10];
 
 
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i = 0;i<10;++i){
		for(int j = 0;j<10;++j){
			if(s.length()==1){
				cout << 0;
				if(j==9)cout << endl;
				else cout << " " ;
				continue;
			}
			int flag  =0;
			ll num =0;
			for(int m = 0;m<10;++m)
				for(int n = 0;n<10;++n)dp[m][n] = 20;
			for(int l = 0;l<s.length()-1;++l){
				if(dp[s[l]-'0'][s[l+1]-'0']<20){
					num+=dp[s[l]-'0'][s[l+1]-'0'];
					continue;
				}
				flag = 0;
				for(int m = 0;m<10;++m){
					for(int n = 0;n<10;++n){
						if(m==0&&n==0)continue;
						//cout << s[i]-'0'+m*i+n*j << endl;
					if((s[l]-'0'+m*i+n*j)%10==s[l+1]-'0'){
						dp[s[l]-'0'][s[l+1]-'0'] = min(dp[s[l]-'0'][s[l+1]-'0'],max(m+n-1,0)),flag = 1;
						//cout << "gsfdgsd" << endl;
					}
				}
			}
			
			if(flag == 0){
				//cout << l << " fdgsdf" << endl;
				break;
			}
			/*
			if(dp[s[l]-'0'][s[l+1]-'0']==0x3f3f3f3f){
				num =-1;
				break;
			}*/
			num+=dp[s[l]-'0'][s[l+1]-'0'];
			}
			//cout << num  << endl;
			if(flag==0){
				cout << -1 ;
				if(j==9)cout << endl;
				else cout << " ";
				continue;
			}
			cout << num ;
			if(j==9)cout << endl;
				else cout << " ";
		}
	}
	return 0;
}
