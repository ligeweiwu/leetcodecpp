#include<stdio.h>
#include <iostream>
#include<vector>
#include<stack>
#include <unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        /*
        unordered_map<char,int> map;
        int n=s.length();
        int left=0;
        //int right=0;
        int res=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(map.count(s[i])==1 && map[s[i]]>=left)
            {
                left=map[s[i]]+1;
            }
            map[s[i]]=i;
            //right=i;
            res=max(res,i-left+1);
        }
        
        return res;
        */
        unordered_map<char,int> map;
        int n=s.length();
        int left=0;
        //int right=0;
        int res=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(map.count(s[i])==1)
            {
                if(map[s[i]]>=left)
                    left=map[s[i]]+1;
            }
            map[s[i]]=i;
            //right=i;
            res=max(res,i-left+1);
        }
        
        return res;
    }
	
	int lengthOfLongestSubstring2(string s) {        
			vector<int> map(128,0);
			vector<int> record(128,0);
			int n=s.length();
			int left=0;
			int res=0;
			int i; 
			for(i=0;i<n;i++)
			{
				if(map[s[i]]>=left && record[s[i]]>0)
				{
					left=map[s[i]]+1;
				}
				map[s[i]]=i;
				record[s[i]]=record[s[i]]+1;
				if(i-left+1>res)
				{
					res=i-left+1;
				}
			}
			return res;
		}
		
	int lengthOfLongestSubstring3(string s) {        
        vector<int> map(128,-1);
        int n=s.length();
        int left=0;
        int res=0;
        int i; 
        for(i=0;i<n;i++)
        {
            if(map[s[i]]>=left)
            {
                left=map[s[i]]+1;
            }
            map[s[i]]=i;
            if(i-left+1>res)
            {
                res=i-left+1;
            }
        }
        return res;
    }
	
	int lengthOfLongestSubstrin4(string s) {  //bao li qiu jie, but it has time limited error in leet code, how to solve it ???????????????????????????????????        
        int n=s.size();
        int res=0;
        int i;
        int j;
            for(i=0;i<=n-1;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(isrepeat(i, j, s))
                    {
                        break;
                    }
                }
                res=max(res,j-i);
            }
        return res;
    }
    
    bool isrepeat(int start, int end, string s)
    {
        unordered_set<char> set;
        for(int i=start;i<=end;i++)
        {
            if(set.count(s[i]))
            {
                return true;
            }
            set.insert(s[i]);
        }
        return false;
    }
	
	int lengthOfLongestSubstring5(string s) {        
        int n=s.size();
        int res=0;
        unordered_set<char> set;
        int i=0;
        int count=0;
        while(i<n)
        {
            if(!set.count(s[i]))
            {
                set.insert(s[i]);
                if(set.size()>res)
                {
                    res=set.size();
                }
                i++;
            }
            else
            {
                set.erase(s[count++]);
            }
        }
        return res;
    }
};

int main()
{
	return 0;
}