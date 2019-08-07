#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int head[3*maxn];

int _find(int x){
	if(head[x]==x)return x;
	return head[x] = _find(head[x]);
}

void _union(int x,int y){
	int hx =_find(x),hy =_find(y);
	if(hx==hy)return;
	head[hx] = hy;
}

int main(){
	ios::sync_with_stdio(false);
	int cnt = 0;
	int n,k;
	cin >> n >> k ;
	for(int i= 1;i<=3*n;++i)head[i] = i;
	int ord,x,y;
	for(int i = 1;i<=k;++i){
		cin >> ord >> x >> y;
		if(x>n||y>n){
			cnt++;continue;
		}
		int hx1 = _find(x),hy1 = _find(y);
		int hx2 = _find(x+n),hy2 = _find(y+n);
		int hx3  = _find(x+2*n),hy3 = _find(y+2*n);
		if(ord==1){
			if(hx1==hy2||hx1 == hy3){
				cnt++;
				continue;
			}
			else{
				_union(x,y);
				_union(x+n,y+n);
				_union(x+2*n,y+2*n);
			}
		}
		else{
			if(x==y||hx1==hy1||hx1 == hy2||hy1==hx3){
				cnt++;
				continue;
			}
			else{
				_union(y,x+n);_union(x,y+2*n);
				_union(x+2*n,y+n);
				//head[hy1] = hx2;head[hx1] = hy3;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
