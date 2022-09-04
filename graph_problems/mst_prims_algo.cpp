#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	vector<pair<int,int>> adj[n]; // adj list with edges and weight of that edge
	
	int keys[n];
	bool mst[n];
	int parent[n];

	for(int i=1;i<n;++i)
		keys[i]=INT_MAX,mst[i]=false,parent[i]=-1;

	keys[0]=0;
	mst[0]=true;

	set<pair<int,int>> s;
	pq.push({keys[0],0});
	
	while(!pq.empty()){
		int u=s.begin()->second;
		int w=s.begin()->first;
		mst[u]=true;
		s.erase(s.begin());
		
		for(auto it:adj[u]){
			if(!mst[it] and keys[it] > w){
				parent[it]=u;
				keys[it]=w;
				set.insert({keys[it],w})
			}	
		}	
	}

}
