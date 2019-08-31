#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
/*
可以利用拓扑排序思想优化查询，fail树上更新留到最后拓扑排序更新，入读为1进队，更新。 
*/

struct ac_aut{
	int nx[maxn][26],fail[maxn],cnt[maxn];
	int root,l;
	int  newnode(){   //添加新的结点 
		for(int i = 0;i<26;++i)nx[l][i] = -1;
		cnt[l++] = 0;
		return l-1;
	}
	void init(){      //初始化建立trie 
		l = 0;
		root = newnode();       //root初始化为0 
	}
	void insert(string  buf){        //插入模式串 
		int len = buf.length();
		int now = root;
		for(int i = 0;i< len ;++i){
			if(nx[now][buf[i]-'a']==-1)nx[now][buf[i]-'a'] = newnode();   //节点上没有记录则新建节点 
			now = nx[now][buf[i]-'a'];
		}
		cnt[now]++;            
	}
	void build(){                  
		queue<int> Q;
		fail[root] = root;
		for(int i = 0;i<26;++i){
			if(nx[root][i]==-1)nx[root][i] = root;  //如果没有记录，将其修改为 
			else{
				fail[nx[root][i]] = root;
				Q.push(nx[root][i]);
			}
		}
		while(!Q.empty()){
			int now =  Q.front();
			Q.pop();
			for(int i = 0;i<26;++i){
				if(nx[now][i]==-1)nx[now][i] = nx[fail[now]][i];
				else{
					fail[nx[now][i]] = nx[fail[now]][i];
					Q.push(nx[now][i]);
				}
			}
		}
	}
	int query(string buf){
		int len = buf.length();
		int now =  root;
		int res = 0;
		for(int i = 0;i<len;++i){
			now = nx[now][buf[i]-'a'];
			int tem = now;
			while(tem!=root){
				res+=cnt[tem];
				cnt[tem] = 0;
				tem = fail[tem];
			}
		}
		return res;
	}
};

ac_aut ac;

int main(){
	ios::sync_with_stdio(false);
	int n,T;
	cin >> T;
	while(T--){
		cin >> n;
	string s;
	ac.init();
	for(int i = 0;i<n;++i){
		cin >> s;
		ac.insert(s);
	}
	ac.build();
	cin >> s;
	cout << ac.query(s) << endl;
	}
	return 0;
}
