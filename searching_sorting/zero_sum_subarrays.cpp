//link - https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        int prefix_sum=0;
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;++i){
            prefix_sum+=arr[i];
            mp[prefix_sum]++;
            if(prefix_sum==0) ans++;
        }
        for(auto item:mp){
            // cout<<item.first<<" "<<item.second<<endl;
            if(item.second>1){
                int k=item.second;
                ans+=((k*(k-1))/2);
            }
        }
        return ans;
    }
};
