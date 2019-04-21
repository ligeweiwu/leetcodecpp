#include<stdio.h>
#include <iostream>
#include<vector>
#include<stack>
#include <unordered_map>
using namespace std;

struct ListNode  //struct in C++ is like class
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL)// gou zao han shu, chu shi hua lie biao jin xing chu shi hua， like gou zao han shu in class
	{
		
	}
};

class Solution {
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode *current=new ListNode(0);
        ListNode *result=current;
        int carry=0;
        int temp=0;
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        while(l1!=NULL || l2!=NULL)
        {
         
            if(l1==NULL&&l2!=NULL)
            {
                current->val=(l2->val+carry)%10;
                carry=(l2->val+carry>=10?1:0);
            }
            if(l1!=NULL&&l2==NULL)
            {
                current->val=(l1->val+carry)%10;
                carry=(l1->val+carry>=10?1:0);
            }
            if(l1!=NULL&&l2!=NULL)
            {
                current->val=(l1->val+l2->val+carry)%10;
                carry=(l1->val+l2->val+carry>=10?1:0);
            }    
            if(l1!=NULL)
            {
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                l2=l2->next;
            }
            if(l1!=NULL || l2!=NULL)
            {
                current->next=new ListNode(0);
                current=current->next;
            }
            else
            {
                if(carry==1)
                {
                    current->next=new ListNode(1);
                }
            }

        }
        return result;
    }
	
	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        ListNode *current=new ListNode(0);
        ListNode *result=current;
        int carry=0;
        int value1=0;
        int value2=0;
        while(l1!=NULL || l2!=NULL)
        {
            value1=(l1==NULL?0:l1->val);
            value2=(l2==NULL?0:l2->val);
            current->next=new ListNode((value1+value2+carry)%10);
            carry=(value1+value2+carry)/10;
            current=current->next;
            l1=(l1==NULL)?l1:l1->next;
            l2=(l2==NULL)?l2:l2->next;
        }
        if(carry)
        {
            current->next=new ListNode(1);
        }
        return result->next;
    }
	
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry=0) {
        
        if(l1==NULL && l2==NULL)
        {
            if(carry==1)
            {
                ListNode *current=new ListNode(1); 
                return current;
            }
            return NULL;
        }
        ListNode *current=new ListNode(-1);   
        int value1=(l1!=NULL?l1->val:0);
        int value2=(l2!=NULL?l2->val:0);
        current->val=(value1+value2+carry)%10;
        carry=(value1+value2+carry)/10;
        l1=(l1==NULL?NULL:l1->next);
        l2=(l2==NULL?NULL:l2->next);
        current->next=addTwoNumbers(l1,l2,carry);
        return current;
        
    }
};

int main()
{
	cout<<"gege"<<endl;
	return 0;
}