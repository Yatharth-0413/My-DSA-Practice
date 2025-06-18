#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if((mid-1>=0 && mid+1<nums.size()) && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else if(nums[mid]==nums[mid+1]){
                if((mid+2)%2==0) low=mid+2;
                else high=mid-1;
            }
            else{
                if((mid+1)%2==0) low=mid+1;
                else high=mid-2;
            }
        }
        return nums[low];
    }
};