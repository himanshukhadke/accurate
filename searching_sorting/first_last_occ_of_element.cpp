// binary search 

int first_occ(int arr[],int n,int x){
    int ans=-1;
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==x){
            ans=mid;
            e=mid-1;
        }else if(arr[mid]>x){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

int last_occ(int arr[],int n,int x){
    int ans=-1;
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==x){
            ans=mid;
            s=mid+1;
        }else if(arr[mid]>x){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    return {first_occ(arr,n,x),last_occ(arr,n,x)};
}
