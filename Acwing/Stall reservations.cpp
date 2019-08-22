#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

struct t{
	int num;
	int l,r;
	int pre;
};
bool operator < (const t & a,const t & b) {
		return a.r>b.r;
	}
priority_queue<t> p;
bool cmp(t a,t b){
	if(a.l<b.l)return true;
	else if(a.l==b.l&&a.r<b.r)return true;
	else return false;
}
bool cmp2(t a,t b){
	return a.pre<b.pre;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int l,r;
	struct t tt[n+1];
	for(int i = 1;i<=n;++i){
		cin >> tt[i].l >> tt[i].r;
		tt[i].pre = i;
	}
	sort(tt+1,tt+1+n,cmp);
	int cnt = 0;
	for(int i = 1;i<=n;++i){
		if(p.empty()){
			tt[i].num = ++cnt;
			p.push(tt[i]);
		}
		else{
			struct t tem = p.top();p.pop();
			//cout << tem.r << endl;
			if(tt[i].l>tem.r){
				tt[i].num = tem.num;
				p.push(tt[i]);
			}
			else {
				p.push(tem);
				tt[i].num = ++cnt;
				p.push(tt[i]);
			}
		}
	}
	sort(tt+1,tt+1+n,cmp2);
	cout << cnt << endl;
	for(int i =1;i<=n;++i){
		cout << tt[i].num << endl;
	}
	return 0;
}
