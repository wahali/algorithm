#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

priority_queue<int> p;
priority_queue<int,vector<int>,greater<int> >q;

int main(){
	ios::sync_with_stdio(false);
	int t,m,ord,tem;
	cin >> t;
	while(t--){
		cin >> ord >> m;
		while(!p.empty())p.pop();
		while(!q.empty())q.pop();
		cout << ord  << " " << (m+1)/2 << endl;
		for(int i = 1;i <= m ;++i){
			cin >> tem;
			if(!p.empty()){
				if(tem<=p.top())p.push(tem);
				else q.push(tem);
			}
			else if(!q.empty()){
				if(tem>=q.top())q.push(tem);
				else p.push(tem);
			}else{
				p.push(tem);
			}
			while(p.size()>i/2)q.push(p.top()),p.pop();
			while(q.size()>i/2+1)p.push(q.top()),q.pop();
			if(i&1){
				cout << q.top() ;
				if((i+1)%20==0)cout << endl;
				else cout << " ";
			}
	}
	if((m+1)%20!=0)cout << endl;
}
	return 0;
}
