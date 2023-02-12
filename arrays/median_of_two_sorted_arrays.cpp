// solution video https://youtu.be/NTop3VTjmxk
// link - https://leetcode.com/problems/median-of-two-sorted-arrays/description/


/* median will be the middle element of merged array
   divide the array into two halfs check if they satisfy the condition that
   all the elements in first half less than all the elements in right  half.
*/



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size();
        int m=nums2.size();
        int low=0;
        int high=n;
        while(low<=high){
            int cut1=(low+high) >> 1;  				// take cut1 elements from first array
            int cut2=((n+m+1)/2) - cut1;			// check how many element we can take from second array (half-cut1 elements)
            int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];      // if we took 0 elements from arr1 in first half
            int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];      // if we took 0 elements from arr1 in first half

            int right1 = cut1==n ? INT_MAX : nums1[cut1];	// if we take all elements from arr1 in first half
            int right2 = cut2==m ? INT_MAX : nums2[cut2]; 	// if we take all elements from arr2 in first half

            if(left1<=right2 and left2<=right1){		// check if we got the correct partition and return the ans 
                if((n+m)&1){
                    return max(left1,left2);			// only one elment will be median if array is odd.
                }else{
                    return (double)((max(left1,left2))+(min(right1,right2)))/2;   // average of two elements will be median
                }
            }else if(left1 > right2){ 				// take less elements from first array 
                high=cut1-1;  
            }else{
                low=cut1+1;                  			// take more elements from first array
            }
        }
        return 0.0;
    }
};
