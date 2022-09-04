bool dfs(int i,vector<int> adj[],vector<int>& color){
    if(color[i]==-1) color[i]=1;
    for(auto u:adj[i]){
        if(color[u]==-1){
            color[u]=1-color[i];
            if(!dfs(u,adj,color)) return false;
        }else if(color[u]==color[i]) return false;
    }
    return true;
}

bool isBipartite(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    int m=edges.size();
    for(int i=0;i<m;++i){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> color(n,-1);
    for(int i=0;i<n;++i){
        if(color[i]==-1){
            if(!dfs(i,adj,color)){
                return 0;
            }
        }
    }
    return 1;
}
