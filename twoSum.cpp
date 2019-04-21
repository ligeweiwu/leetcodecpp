
#include<stdio.h>
#include <iostream>
#include<vector>
#include<stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {   //bao li qiu jie fa, faster
        vector<int> indices;
        int i;
        int j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    break;
                }
            }
        }
        return indices;
    }
	
	vector<int> twoSum2(vector<int>& nums, int target) {   //bao li qiu jie fa, slower
        vector<int> indices;
        int i;
        int j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                }
            }
        }
        return indices;
    }
	
	vector<int> twoSum3(vector<int>& nums, int target)  //hash map, first store nums in hash map, then scan the rest value, whether it is in hash map.
	{
		unordered_map<int,int> map;
        vector<int> indices;
        int i;
        int t;
        for(i=0;i<nums.size();i++)
        {
            map[nums[i]]=i;
        }
        for(i=0;i<nums.size();i++)
        {
            t=target-nums[i];
            if((map.count(t)==1)&&(map[t]!=i))
            {
                indices.push_back(i);
                indices.push_back(map[t]);
                break;
            }
        }
        return indices;
	}
	
	vector<int> twoSum4(vector<int>& nums, int target)  //hash map, like insert sorting, it is very interesting, insert sorting and hash map algorithm
	{
		unordered_map<int,int> map;
        vector<int> indices;
        int i;
        int t;
        for(i=0;i<nums.size();i++)
        {
           t=target-nums[i];
            if(map.count(t)==1)
            {
                indices.push_back(i);
                indices.push_back(map[t]);
            }
            map[nums[i]]=i;
        }
        return indices; 
	}
	
	vector<int> twoSum5(vector<int>& nums, int target)  //hash map, like insert sorting, it is very interesting, insert sorting and hash map algorithm, the best algorithm
	{
		unordered_map<int,int> map;
        int i;
        int t;
        for(i=0;i<nums.size();i++)
        {
           t=target-nums[i];
            if(map.count(t)==1)
            {
                return{map[t],i};
            }
            map[nums[i]]=i;
        }
        return {};
	}
	
};

int main()
{
	return 0;
}