// insertion sort


    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;++i){
	    	int key=arr[i]; // store key to insert at it's correct position
	    	int j=i-1;
	    	while(j>=0 and arr[j]>key){
	    		arr[j+1]=arr[j];
	      		--j;
	    	}
	    	arr[j+1]=key; // inserted to it's correct position
	    }
    }
