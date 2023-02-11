// stuck because of search space was 0 , 100000
// link https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1 


class Solution 
{
    public:
    
    bool is_safe(int a[],int n,int m,int mid){
        int total_pages=0;
        int stud=1;
        for(int i=0;i<n;++i){
            if(total_pages+a[i]>mid){
                ++stud;
                if(stud>m)return false;
                total_pages=a[i];
            }else
                total_pages+=a[i];
        }
        return true;
    }
    
    int allocate(int a[],int n,int m){
        // sort(a,a+n);
        if(m>n) return -1;
        int s=a[n-1];
        int e=accumulate(a,a+n,0);
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            // cout<<s<<" "<<e<<" "<<mid<<endl;
            // cout<<mid<<" ";
            if(is_safe(a,n,m,mid)){
                ans=min(ans,mid);
                e=mid-1;
            }else   
                s=mid+1;
        }
    }
    
    
    int findPages(int A[], int N, int M) 
    {
        return allocate(A,N,M);
    }
};
