#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
map<int,int> p;

int main(){
	ios::sync_with_stdio(false);
	for(int i = 3;i <= 500;++i){
		for(int j = 1;j<i-1;++j){
			if(180*j%i==0&&p[180*j/i]==0)p[180*j/i] = i;
		}
	}
	
	for(int i = 1;i<180;++i){
		//cout << i <<" " << p[i]<< endl;
	}
	int t;
	cin >> t;
	double ang;
	while(t--){
		cin >> ang;
		cout << p[ang] << endl;
	}
	return 0;
}
