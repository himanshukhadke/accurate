// note - this question has asked to me in a interview
// link - https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        long long int mul=1;
        int flag=0;
        
        vector<long long int> ans(n,0);
        for(int i=0;i<n;++i){
            if(flag==0 and nums[i]==0){
                flag=1;
                continue;
            }
            mul*=nums[i];
            if(mul==0) return ans;
        }
        
        for(int i=0;i<n;++i){
            if(flag==1){
                if(nums[i]==0)
                    ans[i]=mul;
                else
                    ans[i]=0;
            }else 
               ans[i]=mul/nums[i];
        }   
        
    }
