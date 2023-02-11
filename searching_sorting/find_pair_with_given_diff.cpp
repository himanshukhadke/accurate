// link - https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

int bi_search(int arr[],int n,int key){
    int s=0;
    int e=n-1;  
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) e=mid-1;
        else s=mid+1;
    }
    return -1;
}

bool findPair(int arr[], int size, int n){
    //code
    sort (arr,arr+size);
    for(int i=0;i<size;++i){
        int k=abs(n-arr[i]);
        int idx=bi_search(arr,size,k);
        if(idx!=-1 and idx!=i){
            return true;
        }
    }
    return false;
}
