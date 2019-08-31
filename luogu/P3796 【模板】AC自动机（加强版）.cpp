#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
#define debug(a) cout << #a << ": " << a << endl;

struct ac_aut{
	int nx[maxn][26],fail[maxn],cnt[maxn];
	int root,l;
	int st[200],tt,num[maxn];
	//map<int,int> p;
	string str[200];
	int  newnode(){   //添加新的结点 
		for(int i = 0;i<26;++i)nx[l][i] = -1;
		cnt[l++] = 0;
		return l-1;
	}
	void init(){      //初始化建立trie 
		l = 0;
		tt = 0;
		memset(num,0,sizeof(num));
		//p.clear();
		root = newnode();       //root初始化为0 
	}
	void insert(string  buf){        //插入模式串 
		int len = buf.length();
		int now = root;
		for(int i = 0;i< len ;++i){
			if(nx[now][buf[i]-'a'] == -1)nx[now][buf[i]-'a'] = newnode();   //节点上没有记录则新建节点 
			now = nx[now][buf[i]-'a'];
		}
		cnt[now]++; 
		st[++tt] = now;           
	}
	void build(){    
	//cout << "ddddddddddddddddddd" << endl;              
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
			//cout << now << endl;
			Q.pop();
			for(int i = 0;i<26;++i){
				if(nx[now][i]==-1)nx[now][i] = nx[fail[now]][i];
				else{
					fail[nx[now][i]] = nx[fail[now]][i];
					Q.push(nx[now][i]);
				}
			}
		}
		//cout << "dsgfdgsdg" << endl;
	}
	int query(string buf){
		int len = buf.length();
		int now =  root;
		int MAX = 0;
		int res = 0;
		for(int i = 0;i<len;++i){
			now = nx[now][buf[i]-'a'];
			int tem = now;
			while(tem!=root){
				//if(cnt[tem]==-1)break;
				num[tem]+=cnt[tem];
				//p[tem]+=cnt[tem];
				MAX = max(MAX,num[tem]);
				//cnt[tem] = -1;
				tem = fail[tem];
			}
		}
		return MAX;
	}
};

ac_aut ac;

int main(){
	ios::sync_with_stdio(false);
	int n,T;
	while(cin>>n){
	if(n==0)break;
	string s;
	ac.init();
	for(int i = 1;i<=n;++i){
		cin >> s;
		ac.str[i] = s;
		ac.insert(s);
	}
	ac.build();
	cin >> s;
	int MAX = ac.query(s);
	cout << MAX<< endl;
	for(int i = 1;i<=n;++i){
		if(ac.num[ac.st[i]]==MAX)cout << ac.str[i]<< endl;
	}
	}
	return 0;
}
