#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
ll t1,t2,x1,x2,t0;
ll yy,y2;
ll fy1,fy2;
double ct = 1e99,t;
int main(){
	ios::sync_with_stdio(false);
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	while(x1 >= 0&&x2 >=0){
		t = (t1*x1 + t2*x2*1.0)/(x1*1.0+x2);
		if(t < t0){x1--;continue;}
		if(t < ct){
			ct = t;
			fy1 = x1,fy2 = x2;
		}
		x2 --;
	}
	cout << fy1 << ' ' << fy2 << endl;
	return 0;
}

