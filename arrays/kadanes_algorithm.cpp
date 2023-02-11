    long long maxSubarraySum(int arr[], int n){
       int mx=arr[0];
       int sum=0;
       for(int i=0;i<n;++i){
           mx=max(mx,arr[i]);
           mx=max(sum+=arr[i],mx);
           if(sum<0)sum=0;
       }
       return mx;
    }
