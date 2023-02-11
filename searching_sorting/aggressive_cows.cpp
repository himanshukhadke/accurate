// this problem is bases on monotonic search spaces
// link to prob - https://www.spoj.com/problems/AGGRCOW/



#include <bits/stdc++.h>
using namespace std;

bool is_safe(int arr[],int n,int dis,int cows){
	int prev=arr[0];
	int c=1;
	for(int i=1;i<n;++i){
		if(arr[i]-prev>=dis){
			c++;
			prev=arr[i];
		} 
		if(c>=cows){
			return true;
		}
	}
	if(c<cows){
		return false;
	}
	return true;
}

int distance(int arr[],int n,int cows){
	sort(arr,arr+n);
	int s=1;
	int e=arr[n-1];
	int ans=-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(is_safe(arr,n,mid,cows)){
			ans=mid;
			s = mid+1;
		}else{
			e = mid-1;
		}
	}
	return ans;
}

int main() {
	int n,cows;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>cows;
		int arr[n];
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
		cout<<distance(arr,n,cows)<<endl;
	}
	return 0;
}
