// link - https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1


    int smallestSubWithSum(int arr[], int n, int x)
    {
        int i=0,j=0;
        int sum=0;
        int ans=INT_MAX;
        int flag=1; // to determine we need to add current element to sum or wait to minimize the subarray size
        while(j<n){
            if(flag==1) // add only when we are incrementing sum
                sum+=arr[j];
            if(sum>x){ 
                ans=min(ans,j-i+1);
                sum-=arr[i]; // we have got the sum greater check if we can reduce the suarray size.
                ++i;
                flag=0;
            }else{
                flag=1;
                ++j;
            }
        }
        return ans;
    }
