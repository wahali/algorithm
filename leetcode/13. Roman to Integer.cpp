#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;

int romanToInt(string s) {
    int len =  s.length();
    int ans = 0;
    for(int i = 0;i < len;++i){
    	switch(s[i]){
    		case 'I':{
    			if(i != len - 1){
    				if(s[i+1] == 'V')ans += 4,i++;
    				else if(s[i+1] == 'X')ans += 9,i++;
    				else ans += 1;
				}
				else ans += 1;
				break;
			}
			case 'X':{
				if(i != len - 1){
    				if(s[i+1] == 'L')ans += 40,i++;
    				else if(s[i+1] == 'C')ans += 90,i++;
    				else ans += 10;
				}
				else ans += 10;
				break;
			}
			case 'C':{
				if(i != len - 1){
    				if(s[i+1] == 'D')ans += 400,i++;
    				else if(s[i+1] == 'M')ans += 900,i++;
    				else ans += 100;
				}
				else ans += 100;
				break;
				break;
			}
			case 'V':ans += 5;break;
			case 'L':ans += 50;break;
			case 'D':ans += 500;break;
			case 'M':ans += 1000;break;
		}
	}
	return ans;
}

int main(){
	string s;
	while(1){
		cin >> s;
		cout << romanToInt(s) << endl;
	}
	return 0;
}
