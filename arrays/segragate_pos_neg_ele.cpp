//Doutch National Flag Algorithm

void solve(){
	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, 11};
  	int arr_size = sizeof(arr) / sizeof(arr[0]);
  	int  i=0,j=0;
  	while(j<arr_size){
  		if(arr[j]<0) swap(arr[i++],arr[j++]);
  		else ++j;
  	}
  	for(int i=0;i<arr_size;++i){
  		cout<<arr[i]<<" ";
  	}cout<<endl;
}
