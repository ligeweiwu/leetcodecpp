#include<stdio.h>
#include<math.h>
#include <iostream>
#include<bits/stdc++.h> 
#include<vector>
#include<stack>
#include <unordered_map>
#include<unordered_set>
using namespace std;



class Solution {
public:
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {  //gui bing pai xu zui hou yi bu
        vector<int> merge;
        int i_nums1=0;
        int i_nums2=0;
        while(i_nums1<nums1.size() || i_nums2<nums2.size())
        {
            if(i_nums1>=nums1.size() && i_nums2<nums2.size())
            {
                merge.push_back(nums2[i_nums2++]);
            }
            else if(i_nums1<nums1.size() && i_nums2>=nums2.size())
            {
                merge.push_back(nums1[i_nums1++]);
            }
            else
            {
                if(nums1[i_nums1]<nums2[i_nums2])
                {
                    merge.push_back(nums1[i_nums1++]);
                }
                else
                {
                    merge.push_back(nums2[i_nums2++]);
                }
            }
        }
        int n=(nums1.size()+nums2.size())/2;
        if((nums1.size()+nums2.size())%2==0)
        {
            return (double)(merge[n]+merge[n-1])/2;
        }
        else
        {
            return (double)merge[n];
        }  
    }
	
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int i;
        int nums1_i=0;
        int nums2_i=0;
        int nums1_record=0;
        int nums2_record=0;
        int length=(nums1.size()+nums2.size());
        int  direction=0;
        int before=0;
        double result;
        if(nums1.size()==0)
        {
            if(length%2==0)
            {
                return (double)(nums2[length/2]+nums2[length/2-1])/2;
            }
            else
            {
                return (double)nums2[length/2];
            }
        }
        if(nums2.size()==0)
        {
            if(length%2==0)
            {
                return (double)(nums1[length/2]+nums1[length/2-1])/2;
            }
            else
            {
                return (double)nums1[length/2];
            }
        }
        for(i=0;i<=length/2;i++)
        {
            if(direction==1)
            {
                before=(nums2_i>0?nums2[nums2_i-1]:nums2[0]);
            }
            if(direction==0)
            {
                before=(nums1_i>0?nums1[nums1_i-1]:nums1[0]);
            }
            if(nums1_i>=nums1.size() && nums2_i<nums2.size())
            {
                nums2_i++;
                nums2_record=i;
                direction=1;
            }
            else if(nums1_i<nums1.size() && nums2_i>=nums2.size())
            {
                nums1_i++;
                nums1_record=i;
                direction=0;
            }
            else
            {
                if(nums1[nums1_i]<nums2[nums2_i])
                {
                    nums1_i++;
                    nums1_record=i;
                    direction=0;
                }
                else
                {
                    nums2_i++;
                    nums2_record=i;
                    direction=1;
                }
            }
        }
        if(length%2==0)
        {
            if(nums1_record==i-1)
            {
                result=(double)(nums1[nums1_i-1]+before)/2;
            }
            else if(nums2_record==i-1)
            {
                result=(double)(nums2[nums2_i-1]+before)/2;
            }
            return result;
        }
        else
        {
            if(nums1_record==i-1)
            {
                result=double(nums1[nums1_i-1]);
            }
            else if(nums2_record==i-1)
            {
                result=double(nums2[nums2_i-1]);
            }
            return result;
        }
    }
	
	double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
        int length=nums1.size()+nums2.size();
        int nums1_i=0;
        int nums2_i=0;
        if(length%2==0)
        {
            double a1=(double)findkth(nums1, nums2, nums1_i, nums2_i, length/2+1);
            double a2=(double)findkth(nums1, nums2, nums1_i, nums2_i, length/2);
            return (a1+a2)/2;
        }
        else
        {
            return (double) findkth(nums1, nums2, nums1_i, nums2_i, length/2+1);
        }
    }
	
	double findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2) {  // the import idea for this binary research is using some imaginary position
        int n1=nums1.size();   // for an array, which has n numbers, it has 2*n+1 cut positions
        int n2=nums2.size();   // math is important!!!!!!!!!!!!!!! analyse it!!!!!!!!!!!, binary research must on the short array, mathematic to annlyse it
        if(n1>n2)// binary research on long array has boundary problem
        {
            return findMedianSortedArrays4(nums2,nums1);
        }
        int low1=0;
        int high1=2*n1;
        while(low1<=high1)
        {
            int med1=(low1+high1)/2;
            int med2=n1+n2-med1; //important,genius thinking, use mathematic to analyse it, numerisch analyze
            int left1=(med1==0?INT_MIN:nums1[(med1-1)/2]);   //important
            int right1=(med1==2*n1?INT_MAX:nums1[(med1)/2]);
            int left2=(med2==0?INT_MIN:nums2[(med2-1)/2]);
            int right2=(med2==2*n2?INT_MAX:nums2[(med2)/2]);
            if(left1>right2) //binary research to find the cut position, genius thinking, see reference blog
            {
                high1=med1-1;
            }
            else if(left2>right1)
            {
                low1=med1+1;
            }
            else
            {
                return (double)(max(left1,left2)+min(right1,right2))/2;
            }
            
        }
        return -1.0;
    }
	
	double findMedianSortedArrays5(vector<int>& nums1, vector<int>& nums2) {// the import idea for this binary research is using the cut position, which represents the number of elements
        int n1=nums1.size();  //index 0...n cut position, which represents number of elements
        int n2=nums2.size();  // math is important!!!!!!!!!!!!!!! analyse it!!!!!!!!!!!, binary research must on the short array, mathematic to annlyse it
        if(n1>n2)
        {
            return findMedianSortedArrays5(nums2,nums1);
        }
        int num_median=(n1+n2+1)/2; //important,genius thinking, use mathematic to analyse it, numerisch analyze, number of elements in half array
		int low=0;
        int high=n1;
        while(low<=high)
        {
            int cut1=(low+high)/2; //important,genius thinking, use mathematic to analyse it, numerisch analyze, number of elements in half array
            int cut2=num_median-cut1;
            int left1=(cut1==0?INT_MIN:nums1[cut1-1]);
            int left2=(cut2==0?INT_MIN:nums2[cut2-1]);
            int right1=(cut1==n1?INT_MAX:nums1[cut1]);
            int right2=(cut2==n2?INT_MAX:nums2[cut2]);
            if(left1>right2)//binary research to find the cut position, genius thinking, see reference blog
            {
                high=cut1-1;
            }
            else if(left2>right1)
            {
                low=cut1+1;
            }
            else
            {
                if((n1+n2)%2==0)
                {
                    return (double)(max(left1,left2)+min(right1,right2))/2;
                }
                else
                {
                    return (double)max(left1,left2);
                }
            }
        }
        return -1.0;
    }
	
     
private:
    int findkth(vector<int>& nums1, vector<int>& nums2, int nums1_i, int nums2_i, int kth){    //bi huan di gui si lu, kth>=1, based on k/2 search
        if(nums1_i>=nums1.size())   //nums1_i and nums2_i are current  position for scanning array
        {
            return nums2[nums2_i+kth-1];
        }
        if(nums2_i>=nums2.size())
        {
            return nums1[nums1_i+kth-1];
        }
        if(kth==1)
        {
           if(nums1[nums1_i]<=nums2[nums2_i])
           {
               return nums1[nums1_i];
           }
           else
           {
               return nums2[nums2_i];
           }
        }
        if(nums1_i+kth/2-1>=nums1.size())
        {
            return findkth(nums1,nums2,nums1_i,nums2_i+kth/2,kth-kth/2);
        }
        if(nums2_i+kth/2-1>=nums2.size())
        {   
            return findkth(nums1,nums2,nums1_i+kth/2,nums2_i,kth-kth/2);
        }
        if(nums1[nums1_i+kth/2-1]<=nums2[nums2_i+kth/2-1])
        {
            return findkth(nums1,nums2,nums1_i+kth/2,nums2_i,kth-kth/2);
        }
        else
        {
            return findkth(nums1,nums2,nums1_i,nums2_i+kth/2,kth-kth/2);
        }
    }
	
	int findkth1(vector<int>& nums1, vector<int>& nums2, int nums1_i, int nums2_i, int kth){  //bi huan di gui si lu, kth>=1, based on i_1+i_2==kth serach
        if(nums1_i>=nums1.size())  //nums1_i and nums2_i are current  position for scanning array
        {
            return nums2[nums2_i+kth-1];
        }
        if(nums2_i>=nums2.size())
        {
            return nums1[nums1_i+kth-1];
        }
        if(kth==1)
        {
           if(nums1[nums1_i]<=nums2[nums2_i])
           {
               return nums1[nums1_i];
           }
           else
           {
               return nums2[nums2_i];
           }
        }
        int i_1=(nums1_i+kth/2-1>=nums1.size()?nums1.size()-1-nums1_i:kth/2-1);
        int i_2=(nums2_i+kth/2-1>=nums2.size()?nums2.size()-1-nums2_i:kth/2-1);
        if(nums1[nums1_i+i_1]<=nums2[nums2_i+i_2])
        {
            return findkth(nums1,nums2,nums1_i+i_1+1,nums2_i,kth-i_1-1);
        }
        else
        {
            return findkth(nums1,nums2,nums1_i,nums2_i+i_2+1,kth-i_2-1);
        }
    }
	
};

int main()
{
	return 0;
}