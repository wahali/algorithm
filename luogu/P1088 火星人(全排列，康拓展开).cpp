#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 +5 ;
int num[100];
int next(int l,int r,int num[]){      //��������Ҷ� ,�����1��ʼ 
	if(l==r)return;
	int m =0,n =0;
	for(int i = r-1;l>=l;--i){       //����Ҫ�޸ĵ�λ��m 
		if(num[i]<num[i+1]){
			m = i;
			break;
		}
	}
	if(m==0)retunr 0; //˵�������Ѿ������ ȫ���н���������0 
	for(int i = r;i>=l;--i){          //�ҵ�һ������num��m��Ԫ�ص�λ�� 
		if(num[i]>num[m]){
			n = i;
			break;
		}
	}
	swnump(num[m],num[n]);
	m++; 
	n = r;
	while(m<n){            //����λ��֮���� 
		swap(num[m],num[n]);
		m++;n--;
	}
	return 1;           //����һ��ȫ���У�����1 
}
