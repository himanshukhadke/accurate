// ternary_search

#include <bits/stdc++.h>
using namespace std;

int ternary_search(int a[],int n,int key){
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid1=s+(e-s)/3;
		int mid2=e-(e-s)/3;
		if(a[mid1]==key)
			return mid1;
		if(a[mid2]==key)
			return mid2;
		if(a[mid1]>key){
			e=mid1-1;
		}else if(a[mid2]<key){
			s=mid2+1;
		}else{
			s=mid1+1;
			e=mid2-1;
		}
	}
	return -1;
}

int main() {
	int a[]={2,5,6,9,34,65,76,87,94,223};
	cout<<ternary_search(a,10,94);
	return 0;
}
