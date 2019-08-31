#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
/*
����������������˼���Ż���ѯ��fail���ϸ��������������������£����Ϊ1���ӣ����¡� 
*/

struct ac_aut{
	int nx[maxn][26],fail[maxn],cnt[maxn];
	int root,l;
	int  newnode(){   //����µĽ�� 
		for(int i = 0;i<26;++i)nx[l][i] = -1;
		cnt[l++] = 0;
		return l-1;
	}
	void init(){      //��ʼ������trie 
		l = 0;
		root = newnode();       //root��ʼ��Ϊ0 
	}
	void insert(string  buf){        //����ģʽ�� 
		int len = buf.length();
		int now = root;
		for(int i = 0;i< len ;++i){
			if(nx[now][buf[i]-'a']==-1)nx[now][buf[i]-'a'] = newnode();   //�ڵ���û�м�¼���½��ڵ� 
			now = nx[now][buf[i]-'a'];
		}
		cnt[now]++;            
	}
	void build(){                  
		queue<int> Q;
		fail[root] = root;
		for(int i = 0;i<26;++i){
			if(nx[root][i]==-1)nx[root][i] = root;  //���û�м�¼�������޸�Ϊ 
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
