#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 +5 ;
int num[100];
int next(int l,int r,int num[]){      //数组的左右端 ,数组从1开始 
	if(l==r)return;
	int m =0,n =0;
	for(int i = r-1;l>=l;--i){       //找需要修改的位置m 
		if(num[i]<num[i+1]){
			m = i;
			break;
		}
	}
	if(m==0)retunr 0; //说明序列已经最大了 全排列结束，返回0 
	for(int i = r;i>=l;--i){          //找第一个大于num【m】元素的位置 
		if(num[i]>num[m]){
			n = i;
			break;
		}
	}
	swnump(num[m],num[n]);
	m++; 
	n = r;
	while(m<n){            //参照位置之后倒序 
		swap(num[m],num[n]);
		m++;n--;
	}
	return 1;           //有下一个全排列，返回1 
}
