//link - https://leetcode.com/problems/find-the-duplicate-number/description/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            int k=abs(nums[i]);
            if(nums[k]<0){
                return k;
            }
            nums[k]*=-1;
        }
        return -1;
    }
};
