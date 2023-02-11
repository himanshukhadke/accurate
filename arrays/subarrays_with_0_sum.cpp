// link - https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,int> mp;
        int temp=0;
        for(int i=0;i<n;++i){
            temp+=arr[i];
            if(mp[temp]!=0){
                return true;
            }
            mp[temp]++;
        }
        if(mp[0])
            return true;
        return false;
    }


//link - https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
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
            if(item.second>1){
                int k=item.second;
                ans+=((k*(k-1))/2);
            }
        }
        return ans;
    }
