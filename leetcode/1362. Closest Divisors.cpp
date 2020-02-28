#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;
vector<int> closestDivisors(int num) {
	int MIN = num+2;
	int a = 0,b = 0;
	for(int i = sqrt(num+1);i>=1;--i){
		if((num+1)%i==0){
			if(abs((num+1)/i-i)<MIN){
				MIN = abs((num+1)/i-i);
				a = i;
				b = (num+1)/i;
				
			}
		break;
		}
	}   
	for(int i = sqrt(num+2);i>=1;--i){
		if((num+2)%i==0){
			if(abs((num+2)/i-i)<MIN){
				MIN = abs((num+2)/i-i);
				a = i;
				b = (num+2)/i;
				
			}
		break;
		}
	}    
	return vector<int>{a,b};
}

int main(){
	
	return 0;
}
