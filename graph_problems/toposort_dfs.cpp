class Solution
{
	public:
	vector<int> topo;
	void dfs(vector<int> adj[],int k,vector<int>& vis){
	    vis[k]=1;
	    for(auto i:adj[k]){
	       if(!vis[i])dfs(adj,i,vis);
	    }
	    topo.push_back(k);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    for(int i=0;i<V;++i){
	        if(vis[i]==0){
	            dfs(adj,i,vis);
	        }
	    }
	    reverse(topo.begin(),topo.end());
	    return topo;
	}
};
