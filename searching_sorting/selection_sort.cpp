// link https://practice.geeksforgeeks.org/problems/selection-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


class Solution
{
    public:
    void selectionSort(int arr[], int n)
    {
         for(int i=0;i<n;++i){
	    	int temp=INT_MIN;
	    	int idx=-1;
	        for(int j=0;j<n-i;++j){
	        	if(arr[j]>temp){
	        		idx=j;
	        		temp=arr[j];
	        	}
	        }	
        	swap(arr[idx],arr[n-i-1]);
        }
    }
};
