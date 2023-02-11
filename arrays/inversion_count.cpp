
// inversion count using merge sort 


long long merge(long long  a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0, /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = beg;  /* initial index of merged sub-array */  
    long long count=0;  
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {   count+=(n1-i);
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k++] = LeftArray[i++];    
    }    
      
    while (j<n2)    
    {    
        a[k++] = RightArray[j++];    
    }    
    return count;
}    
     
    long long  merge_sort(long long nums[],int s,int e){
        long long count=0;
        if(e>s){
            int mid=(s+e)/2;
            count=merge_sort(nums,s,mid);
            count+=merge_sort(nums,mid+1,e);
            count+=merge(nums,s,mid,e);
        }
        return count;
    } 
     
    long long int inversionCount(long long arr[], long long N)
    {
        return merge_sort(arr,0,N-1);
    }
