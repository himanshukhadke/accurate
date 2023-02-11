// link - https://www.spoj.com/problems/ANARC05B/


#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,m;
	while(1){
	cin>>n;
	if(n==0)break;
	int a[n],prefa[n];
	int sum=0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		sum+=a[i];
		prefa[i]=sum;
	}
	cin>>m;
	int b[m],prefb[m];
	sum=0;
	for(int i=0;i<m;++i){
		cin>>b[i];
		sum+=b[i];
		prefb[i]=sum;
	}
	vector<pair<int,int>> intr;
	for(int i=0;i<n;++i){
		int s=0,e=m-1;
		while(s<=e){
			int mid=(s+e)>>1;
			if(b[mid]==a[i]){
				intr.push_back({i,mid});
				break;
			}else if(b[mid]>a[i]){
				e=mid-1;
			}else{
				s=mid+1;
			}
		}
	}
	int ans=0;
	int preva=0,prevb=0;
	for(int i=0;i<intr.size();++i){
		int x=intr[i].first;
		int y=intr[i].second;
		if(prefa[x]-preva>=prefb[y]-prevb){
			ans+=prefa[x]-preva;
		}else{
			ans+=prefb[y]-prevb;
		}
		preva=prefa[x];
		prevb=prefb[y];
	}
	if(prefa[n-1]-preva>=prefb[m-1]-prevb){
		ans+=prefa[n-1]-preva;
	}else ans+=prefb[m-1]-prevb;
	cout<<ans<<endl;
	}
	return 0;
	
} 
