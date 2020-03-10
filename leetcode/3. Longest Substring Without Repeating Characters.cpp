#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;
// nlogn
//int lengthOfLongestSubstring(string s) {
//        int len  = s.length();
//        int ans  = 0,cur = 1;
//        map<char,int> mp; 
//        for(int i = 0 ;i < len;++i){
//        	if(mp[s[i]] != 0){
//                cur = max(cur,mp[s[i]]);
//			}
//        	mp[s[i]] = i + 1;
//            ans = max(ans, i + 1 - cur);
//		}
//        return ans ;
//    }

//On
int lengthOfLongestSubstring(string s) {
        int len  = s.length();
        int ans  = 0,cur = -1;
        int mp[128];
        for(int i = 0 ;i < 128;++i)mp[i] = -1;
        for(int i = 0 ;i < len;++i){
        	if(mp[s[i]-' '] != -1){
                cur = max(cur,mp[s[i] - ' ']);
			}
        	mp[s[i] - ' '] = i;
            ans = max(ans, i - cur);
		}
        return ans ;
    }

int main(){
	
	return 0;
}
