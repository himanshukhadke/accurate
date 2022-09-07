class Solution
{
	public:
	vector<int> order;
	vector<bool> used;
	int ans;
	void dfs(int i,vector<int> adj[]){
	    used[i]=true;
	    for(auto it:adj[i])
	        if(!used[it])
	            dfs(it,adj);
        order.push_back(i);
	}
	void dfs2(int i,vector<int> trans[]){
	    used[i]=true;
	    for(auto it:trans[i])
	        if(!used[it])
	            dfs(it,trans);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // int m=adj.size();
        used.assign(V,false);
        for(int i=0;i<V;++i)
            if(!used[i])
                dfs(i,adj);
        used.assign(V,false);
        vector<int> trans[V];
        for(int i=0;i<V;++i){
            for(auto it:adj[i])
                trans[it].push_back(i);
        }
        int k=0;
        reverse(order.begin(),order.end());
        for(auto v:order)
                if(!used[v])dfs2(v,trans),++k;
                
        return k;
    }
};
