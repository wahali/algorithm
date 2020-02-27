#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;

bool isPalindrome(int x) {
	if(x < 0)return false;
	else if(x == 0)return true;
	else{
		int tem = x;
		int wei = 0;
		while(tem){
			wei++;
			tem/=10;
		}
		int pw = 1;
		for(int i = 0;i < wei/2 - 1 ;++i)pw *= 10;
		int res = 0;
		tem = x;
		for(int i = 0;i < wei/2 ;++i){
				res += pw*(tem%10);
				tem /= 10;
				pw /= 10;
		}
		if(wei&1){
			tem /= 10;
		}
		pw = 1;
		for(int i = 0;i < wei/2 ;++i){
				res -= pw*(tem%10);
				tem /= 10;
				pw *= 10;
		}
		if(res == 0)return true;
		else return false;
	}        
}

int main(){
	int x;
	while(1){
	scanf("%d",&x);
	printf("%d",isPalindrome(x));
	}
	return 0;
}
