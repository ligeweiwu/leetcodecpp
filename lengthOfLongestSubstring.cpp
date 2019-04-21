#include<stdio.h>
#include <iostream>
#include<vector>
#include<stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        unordered_map<char,int> map;
        int n=s.length();
        int left=0;
        int right=0;
        int res=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(map.count(s[i])==1 && map[s[i]]>=left)
            {
                left=map[s[i]]+1;
            }
            map[s[i]]=i;
            right=i;
            if(right-left+1>res)
            {
                res=right-left+1;
            }
        }
        
        return res;
    }
};

int main()
{
	cout<<"hehe"<<endl;
	return 0;
}
