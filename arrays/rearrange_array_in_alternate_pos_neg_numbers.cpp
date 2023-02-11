// link - https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

// Below is C/C++ code for input/output
#include<bits/stdc++.h>
#define Fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

void rotate(vector<int>& arr,int outofplace,int cur){
	int key = arr[cur];
	for(int i=cur;i>outofplace;--i){
		arr[i]=arr[i-1];
	}
	arr[outofplace]=key;
}

void solve(){
	int n;
	cin>>n;
	std::vector<int> arr(n);
	for(int &i:arr){
		cin>>i;
	}
	int outofplace=-1;

	for(int i=0;i<n;++i){
		if(outofplace>=0){
			for(int j=outofplace+1;j<n;++j){
				if((arr[outofplace]>=0 and arr[j]<0) ||
					 (arr[outofplace]<0 and arr[j]>=0)){
					rotate(arr,outofplace,j);
					if(j-outofplace>=2)
						outofplace+=2;
					else 
						outofplace=-1;
					break;
				}
			}
		}else{
			//at even index positive
			//at odd index negative
			if((i%2==0 and arr[i]<0)||(i%2==1 and arr[i]>=0)){
				outofplace=i;
			}
		}
	}

	for(int i:arr){
		cout<<i<<" ";
	}
}
	

int32_t main()
{
	Fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

