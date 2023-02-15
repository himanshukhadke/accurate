// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1



    int median(vector<vector<int>> &matrix, int R, int C){
        //monotonic search space 
        //lets guess the median
        int s=1;
        int e=2000;
        int med=(R*C+1)/2; // position of median element.
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            // check no. of elements before mid; if it's less than (R*C+1)/2 increse the mid
            int count=0;
            for(int i=0;i<R;++i){
                count+=(lower_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
            }
            if(count<med){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
