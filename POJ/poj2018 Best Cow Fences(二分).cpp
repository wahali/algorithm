#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
double a[maxn],b[maxn];
int n,f;

bool valid(double x){
	double  MIN = 1e10,MAX = -1e10;
	for(int i = 1;i<=n;++i){
		b[i] = a[i]-x;
		b[i] += b[i-1];
	}
	for(int i = f;i<=n;++i){
		MIN = min(MIN,b[i-f]);
		MAX = max(b[i]-MIN,MAX);
	}
	if(MAX>=0)return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> f;
	for(int i = 1;i<=n;++i)cin >> a[i];
	double l = -1e6,r = 1e6,mid;
	while(l+1e-7<r){
		mid = (l+r)/2;
		if(valid(mid))l = mid;
		else r = mid;
	}
	//cout << l << ' ' << r << endl;
	//printf("%lf %lf\n",l,r);
	cout << int(r*1000) ;
	return 0;
}
