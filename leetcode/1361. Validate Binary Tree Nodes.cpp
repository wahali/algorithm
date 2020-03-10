#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        bool ans = false;
        int a[n+5][2];
        for(int i = 0;i < n;++i)a[i][0] = a[i][1]= 0;
        int flag =0,l1 = 0,l2 = 0;
        for(int i = 0;i < n;++i){
        	if(leftChild[i]!=-1)a[leftChild[i]][0]++,l1++;
        	if(rightChild[i]!=-1)a[rightChild[i]][1]++,l2++;
		}
		int cnt = 0;
		for(int i = 0 ;i < n;++i){
			if(a[i][0]==0&&a[i][1]==0)cnt++;
			else if(a[i][0]>=1&&a[i][1]>=1){
				cout << 1 << endl;
				return false;
			}
			else if(a[i][0]>1||a[i][1]>1){
				cout << 2 << endl;
				return false; 
			}
		}
		if(cnt > 1){
			cout << 3 << endl;
			return false;
		}
		if(l1&&l2)flag = 1;
		if(flag)return true;
		else return false;
    }

int main(){
	
	return 0;
}
