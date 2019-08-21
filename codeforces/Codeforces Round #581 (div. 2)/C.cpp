#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2+5;
char m[maxn][maxn];
int v[1000005];
int mm[maxn][maxn];
int flag[1000005];
int main(){
	ios::sync_with_stdio(false);
	int n,t;
	cin >> n;
	for(int i = 1;i<=n;++i)
	for(int j = 1;j<=n;++j)
	cin >> m[i][j];
	cin >> t;
	for(int i = 1;i<=t;++i){
		cin >> v[i];
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			mm[i][j] = 1e9;
			if(i==j)mm[i][j] = 0;
			if(m[i][j]=='1')mm[i][j] = 1;
		}
	}
	for(int k = 1;k<=n;++k){
		for(int i =1;i<=n;++i){
			for(int j = 1;j<=n;++j){
				if(i==j)continue;
				if(mm[i][j]>mm[i][k]+mm[k][j]){
					mm[i][j] = mm[i][k]+mm[k][j];
				}
			}
		}
	}
	int num = 0,tot =  1;
	flag[tot++] = v[1];
	for(int i = 3,l = 1;i<=t;++i){
		if(mm[v[l]][v[i-1]]+mm[v[i-1]][v[i]]==mm[v[l]][v[i]])continue;
		flag[tot++] = v[i-1],l = i-1;
	}
	flag[tot++] = v[t];
	cout << tot-1 << endl;
	for(int i = 1;i<tot;++i){
		cout << flag[i] << ' ';
	}
	return 0;
}
