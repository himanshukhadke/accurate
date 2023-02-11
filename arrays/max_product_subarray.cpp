
// optimized solution 
// link - watch youtube video of knowledge center
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        long long int ans=arr[0];
	    long long int max_ending_here=arr[0];
	    long long int min_ending_here=arr[0];
	    for(int i=1;i<arr.size();++i){
	        int tmp = max_ending_here;
	        max_ending_here=max((long long)arr[i],max((long long )arr[i]*max_ending_here,(long long)arr[i]*min_ending_here));
	        min_ending_here=min((long long)arr[i],min((long long)arr[i]*tmp,(long long)arr[i]*min_ending_here));
	        ans=max(ans,max_ending_here);
	    }
	    return ans;
    }
};



// modified kadanes algorithm
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long int  mx=INT_MIN;
	    long long int  temp=1;
	    for(auto i:arr){
	        temp*=i;
	        mx=max(temp,mx);
	        if(temp==0) temp=1;
	    }
	    temp=1;
	    for(int i=n-1;i>=0;--i){
	        temp*=arr[i];
	        mx=max(temp,mx);
	        if(temp==0) temp=1;
	    }
	    return mx;
	}
};
