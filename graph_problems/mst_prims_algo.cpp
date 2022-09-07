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
		mst[u]=true;
		s.erase(s.begin());
		
		for(auto it:adj[u]){
			int v=it.first;
			int w=it.second;
			if(!mst[v] and keys[v] > w){
				parent[v]=u;
				keys[v]=w;
				set.insert({keys[v],w})
			}	
		}	
	}

}
