#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
#define debug(a) cout<<#a<<": "<<a<<'\n'
int h,w;
ll f[12][1<<11];
bool in_s[1<<11];

int main(){
	ios::sync_with_stdio(false);
	while(cin >> h >> w){
		if(h==0&&w == 0)break;
		for(int i = 0;i < (1 << w); ++ i){
			bool cnt = 0,has_odd = 0;
			for(int j = 0;j<w;++j){
				if((i >> j) & 1)has_odd |= cnt,cnt = 0;      // |=用来检验cnt是否为奇数，即是否存在连续奇数个0 
				else cnt ^= 1;      //偶数加一，奇数减一 
				in_s[i] = has_odd | cnt ? 0 : 1;      //不存在奇数个0，就将状态置为1； 
			}
		}
			f[0][0] = 1;
			for(int i = 1;i<=h;++i){
				for(int j = 0;j<(1<<w);++j){
					f[i][j] = 0;
					for(int k = 0;k<(1<<w);++k){
						if((j & k) == 0 && in_s[j|k]){
							f[i][j] += f[i-1][k];
						}
					}
				}
			}
			cout << f[h][0] << endl;
		
	}
	return 0;
}

