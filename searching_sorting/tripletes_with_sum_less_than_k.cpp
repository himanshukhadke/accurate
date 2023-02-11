// link -- https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1


	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    int count=0;
	    for(int i=0;i<n-2;++i){
	       int j=i+1;
	       int k=n-1;
	       while(j<k){
	           if(arr[i]+arr[j]+arr[k]>=sum){
	               --k;
	           }else{
	               count+=(k-j);
	               ++j;
	           }
	       }
	    }
	    return count;
	}
		 
