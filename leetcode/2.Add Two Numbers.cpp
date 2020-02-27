#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans,*p,*p1,*p2;
        ans = new ListNode(0);
        ans->val = 0;
        ans->next = NULL;
        p = ans;
        p1 = l1,p2 = l2;
        int x1 = p1->val,x2 = p2->val;
        int f1 = 0,f2 = 0;
		int tem = 0;
        p->val = x1 + x2 + tem;
        tem = (x1 + x2 + tem)/10;
        p->val = p->val % 10;
        if(!p1->next||f1){
    			x1 = 0,f1 = 1;
			}
    		else {
    			p1 = p1->next;
    			x1 = p1->val;
			}
			if(!p2->next||f2){
    			x2 = 0,f2 = 1;
			}
    		else {
    			p2 = p2->next;
    			x2 = p2->val;
			}
		while(!f1||!f2){
			ListNode * node = new ListNode(0);
			node -> next = NULL;
			node -> val = x1 + x2 + tem;
			tem = node -> val / 10;
			node -> val = node -> val % 10;
			p->next = node;
			p = p -> next;
			if(!p1->next||f1){
    			x1 = 0,f1 = 1;
			}
    		else {
    			p1 = p1->next;
    			x1 = p1->val;
			}
			if(!p2->next||f2){
    			x2 = 0,f2 = 1;
			}
    		else {
    			p2 = p2->next;
    			x2 = p2->val;
			}
		}
    	if(tem){
    		p->next = new ListNode(0);
    		p = p -> next;
    		p -> val = 1;
    		p -> next = NULL;
		}
		return ans;
}


int main(){
	
	return 0;
}


