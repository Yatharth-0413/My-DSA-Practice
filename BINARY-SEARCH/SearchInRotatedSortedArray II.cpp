#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return true;
            
            else if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;high--;
            }
            else if(nums[low]<=nums[mid]){
                // left part is sorted
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                // right part is sorted
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};

// When nums[low] == nums[mid] == nums[high], you cannot determine which half is sorted. So, you shrink the search space from both ends to skip over the duplicates. 

// nums[low] == nums[mid] == nums[high]  In this case, you can’t tell which side is sorted — because both sides could look the same. Now you can’t say whether: The left side (low to mid) is sorted Or the right side (mid to high) is sorted

// [1,0,1,1,1]
