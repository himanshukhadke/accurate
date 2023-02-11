// link - https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1


    bool find3Numbers(int a[], int n, int X)
    {   
        sort(a,a+n);
        for(int i=0;i<n;++i){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(a[i]+a[j]+a[k]==X){
                    return true;
                }else if(a[j]+a[k]>X-a[i]){
                    k--;
                }else if(a[j]+a[k]<X-a[i]){
                    ++j;
                }
            }
        }
        return false;
    }
