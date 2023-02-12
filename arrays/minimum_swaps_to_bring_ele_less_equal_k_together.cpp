// link - https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1



    int minSwap(int arr[], int n, int k) {
        int count=0,ans=INT_MAX;
        for(int i=0;i<n;++i){
            if(arr[i]<=k)
                count++;
        }
        int i=0;
        int j=0,tmp=0;
        while(j<n){
            if(j-i+1<count){ //creative window for all elements less and equal to k
                if(arr[j]<=k) ++tmp; // count of less equal element in that window
            }else if(j-i+1==count){
                    if(arr[j]<=k) ++tmp;
                    ans=min(ans,count-tmp); // check how many of elements less equal are still outside window and update the answer.
                    if(arr[i]<=k) --tmp;  // while shifting remove the element if present. 
                    ++i; // shift window by 1 element
                    ++j;
                    continue;
            }
            ++j;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
