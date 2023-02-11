void solve(){
	int arr[]={2,4,5,2,3,3,6,3,6,3};
	// reverse(arr,arr+sizeof(arr)/sizeof(int));
	int n=sizeof(arr)/sizeof(int);
	for(int i=0,j=n-1;i<j;++i,--j){
		swap(arr[i],arr[j]);
	}
	for(auto i:arr){
		cout<<i<<" ";
	}cout<<endl;
}
