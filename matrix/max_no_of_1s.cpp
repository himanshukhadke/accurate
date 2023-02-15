// link - https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

// complexity (N+M)


	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int j=m-1;
	    int i=0;
	    int ans=0;
	    int idx=-1;
	    while(j>-1 && i<n){
	        if(arr[i][j]==1){
	            ++ans;
	            idx=i;
	            --j;
	        }else{
	            ++i;
	        }
	    }
	    return idx;
	}
