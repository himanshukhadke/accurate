// link - https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr,int k,int n,int m){
	int sum=0;
	for(int i:arr){
		sum+=i-k>0?i-k:0;
		if(sum>=m)return true;
	}
	return false;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> arr(n);
	int mx=INT_MIN;
	for(int &i:arr){
		cin>>i;
		mx=max(i,mx);
	}
	int s=0;
	int e=mx;
	int ans=-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(check(arr,mid,n,m)){
			ans=mid;
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
