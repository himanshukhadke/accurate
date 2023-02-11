//https://online.codingblocks.com/app/player/264319/content/255977/7568/lecture


#include <bits/stdc++.h>
using namespace std;

float square_root(int n,int p){
	int s=1,e=n;
	float ans=-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(mid*mid==n)
			return mid;
		else if(mid*mid>n){
			e=mid-1;
		}else{
			ans=mid;
			s=mid+1;
		}
	}
	float inc=0.1;
	for(int i=0;i<p;++i){
		while(ans*ans<=n)
			ans+=inc;
		ans-=inc;
		inc/=10;
	}
	return ans;
}

int main() {
	int n=10;
	int p=3;
	cout<<square_root(n,p)<<endl;
	return 0;
}
