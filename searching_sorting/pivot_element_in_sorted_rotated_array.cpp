/**
Given an sorted integer array of size N which is also rotated by an unknown position. Input Array is not monotonically increasing as it is rotated at some unknown pivot element. We have to find the pivot element of array.
Pivot element is the only element in input array which is smaller than it's previous element. A pivot element divided a sorted rotated array into two monotonically increasing array.
*/



#include <iostream>
using namespace std;

int search(int arr[],int n){
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(s==e) return s;
		if(mid>s and arr[mid-1]>arr[mid]){
			return mid;
		}
		if(mid<e and arr[mid]>arr[mid+1]){
			return mid+1;
		}
		if(arr[s]>=arr[mid])e=mid-1;
		else s=mid+1;
	}
	return -1;
}


int main() {
	int array[11] = {16, 18, 22, 25, 1, 3, 5, 6, 7, 10, 14};
	cout<< array[search(array,11)];
	return 0;
}
