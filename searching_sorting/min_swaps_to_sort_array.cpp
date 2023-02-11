// link - https://practice.geeksforgeeks.org/problems/minimum-swaps/1

// sort the array first check if the element are at their correct index if not then we need to make the sorted array as the original array
// giving us the minimum no. of swaps


class Solution 
{
    public:
    
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;++i){
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int ans=0;
	    
	    for(int i=0;i<n;++i){
	        if(i==v[i].second){
	            continue;
	        }else{
	            ans++;
	            swap(v[v[i].second],v[i]);
	            i--;
	        }
	    }
	    return ans;
	}
};
