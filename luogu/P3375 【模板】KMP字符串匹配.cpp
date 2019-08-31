#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int nx[maxn],f[maxn];
int main(){
	ios::sync_with_stdio(false);
	string s;
	string str;
	cin >> str >> s;
	s = " " + s;
	nx[1]  = 0;
	for(int i = 2,j = 0;i<s.length();++i){
		while(j>0&&s[j+1]!=s[i])j = nx[j];		
		if(s[j+1]==s[i])j++;
		nx[i] = j;
	}
	/*
	for(int i = 1;i<s.length();++i){
		cout << nx[i] << endl;
	}
	*/
	str = " " + str;
	for(int i = 1,j = 0;i<str.length();++i){
		while(j>0&&str[i]!=s[j+1])j = nx[j];
		if(str[i]==s[j+1])j++;
		f[i] =  j;
	}
	for(int i = 1;i<str.length();++i){
		if(f[i]==s.length()-1)cout << i - (s.length()-2)<<endl;
	}
	for(int i = 1;i<s.length();++i){
		cout << nx[i] << " " ;
	}
	return 0;
}
