
//solution video - https://online.codingblocks.com/app/player/264319/content/255977/7572/lecture#
//leetcode link - https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
                break;
            }else if(nums[mid]>=nums[s]){
                if(target<=nums[mid] and target>=nums[s])
                    e=mid-1;
                else 
                    s=mid+1;
            }else {
                if(target>=nums[mid] and target<=nums[e])
                    s=mid+1;
                else
                    e=mid-1;
            }
        }
        return -1;
    }
};
