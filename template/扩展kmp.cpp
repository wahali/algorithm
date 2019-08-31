#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
#define debug(a) cout<<#a<<": "<< a << endl
int n,m;
int _next[maxn],_extend[maxn];
void GetNext(string & T,int & m,int _next[]){
	int a = 0,p = 0;
	_next[0] = m;
	for(int i = 1;i < m;++i){
		if(i >= p ||i + _next[i - a] >= p){
			if(i >= p)p = i;
			while(p < m && T[p] == T[p - i])p++;
			_next[i] = p - i;
			a = i;
		}
		else _next[i] = _next[i - a];
	}
}

void GetExtend(string & S,int &n,int _extend[],string & T,int & m,int _next[]){
	int a = 0,p = 0;
	GetNext(T,m,_next);
	for(int i = 0;i < n;++i){
		if(i >= p || i + _next[i-a] >= p){
			if(i >= p)p = i;
			while(p < n && p - i < m &&S[p] == T[p - i])p++;
			_extend[i] = p - i;
			a = i;
		}
		else _extend[i] = _next[i - a];
	}
}


int main(){
	ios::sync_with_stdio(false);
	string a,b;
	cin >> a >> b;
	int lena = a.length(),lenb = b.length();
	GetExtend(a,lena,_extend,b,lenb,_next);
	for(int i = 0;i<b.length();++i){
		cout << _next[i] << " ";
	}
	cout << endl;
	for(int i = 0;i < a.length();++ i){
		cout << _extend[i] << " ";
	}
	cout << endl;
	return 0;
}

