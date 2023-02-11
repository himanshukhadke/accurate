// link - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// using insertion sort technique
		
       void merge(long long arr1[], long long arr2[], int n, int m) 
        {    
             for(int i=0,j=0;i<n;++i){
                if(arr1[i]>arr2[0]){
                    swap(arr1[i],arr2[0]);
                }
                int key=arr2[0];
                j=0;
                for(;j<m and j<m-1;++j){
                    if(arr2[j+1]<key){
                        arr2[j]=arr2[j+1];
                    }else break;
                }
                arr2[j]=key;
             }
        } 
// using gap method
// calculate gap swap gaps positins and divide gap by 2 complexity (n+m)log(n+m)

void merge(long long arr1[], long long arr2[], int n, int m) {
  int gap = ceil((float)(n + m) / 2);
  while (gap > 0) {
    int i = 0;
    int j = gap;
    while (j < (n + m)) {
      if (j < n and arr1[i] > arr1[j]) {
        swap(arr1[i], arr1[j]);
      } else if (j >= n and i < n and arr1[i] > arr2[j - n]) {
        swap(arr1[i], arr2[j - n]);
      } else if (j >= n and i >= n and arr2[i - n] > arr2[j - n]) {
        swap(arr2[i - n], arr2[j - n]);
      }
      ++i;
      ++j;
    }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }
}
