// https://youtu.be/m18Hntz4go8?t=1171

// link - https://leetcode.com/problems/trapping-rain-water/description/

// most optimal two pointer solution
class Solution {
public:
    int trap(vector<int>& arr) {
        
       int l=0; // left pointer
       int r=arr.size()-1; // right pointer
       int left_max=0; // left maximum to l
       int right_max=0; //right maxium to r
       long long int res=0;
       while(l<=r){
           if(arr[l]<=arr[r]){
               if(arr[l]>=left_max) left_max=arr[l];
               else res+=(left_max-arr[l]);
               ++l;
           }else{
               if(arr[r]>=right_max) right_max=arr[r];
               else res+=(right_max-arr[r]);
               --r;
           }
       }
       return res;
    }
};
