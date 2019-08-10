#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 1e6 +5 ;
#define mk(a,b) make_pair(a,b)
map<pair<int,int>,bool> p;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n,i,h,r,x,y;
	cin >> n >> i >> h >> r;
	//a[i]+=r;
	//a[i+1]-=r;
	for(int i = 0;i<r;++i){
		cin >> x >> y;
		if(p[mk(min(x,y),max(x,y))]==0){
			p[mk(min(x,y),max(x,y))]=1;
		}
		else continue;
		a[min(x,y)+1]-=1;
		a[max(x,y)]+=1;
	}
	
	int cha;
	for(int j = 1;j<=n;++j){
		a[j]+=a[j-1];
		if(j==i){
			cha = h - a[j];
		}
	}
	for(int j = 1;j<=n;++j){
	cout << a[j]+cha<<endl;
	}
	return 0;
}
