// using standerd method


#include <bits/stdc++.h>
using namespace std;

//partition 
int partition(int arr[],int s,int e){
	int pivot=arr[e];
	int i=s-1;
	for(int j=s;j<=e-1;++j){
		if(arr[j]<pivot){
			++i;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[e]);
	return i+1;
}

//quick sort
void quick_sort(int arr[],int s,int e){
	if(s<=e){
		int pivot = partition(arr,s,e); 
		quick_sort(arr,s,pivot-1);
		quick_sort(arr,pivot+1,e);
	}
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	quick_sort(arr,0,n-1);
	for(int i=0;i<n;++i){
		cout<<arr[i]<<" ";
	}cout<<endl;
	return 0;
}
