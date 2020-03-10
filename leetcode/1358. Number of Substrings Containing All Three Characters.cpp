#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;

int numberOfSubstrings(string s) {
        int ans = 0 ;
        int len =  s.length();
        int a = 0,b = -1;
        int cnt[27];
        for(int i = 0;i < 26;++i)cnt[i] = 0;
		while(1){
        	if(cnt[0]>0&&cnt[1]>0&&cnt[2]>0){
        		ans += len  - b;
        		cnt[s[a]-'a']--;
        		a++;
			}
			else {
				if(b < len - 1){
					cnt[s[++b]-'a']++;
				}
				else return ans;
			}
		}
    }

int main(){
	
	return 0;
}
