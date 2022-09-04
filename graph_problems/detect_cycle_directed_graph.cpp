bool detectCycle(int i,vector<int>&vis,vector<int>&dfsvis,vector<int> adj[]){
        vis[i]=1;
        dfsvis[i]=1;
        for(auto u:adj[i]){
            if(!vis[u])
                detectCycle(u,vis,dfsvis,adj);
            if(vis[u] and dfsvis[u]){
                return true;
            }
        }
        dfsvis[i]=0;
        return false;
}


bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
        vector<int> adj[v];
        for(int i=0;i<e;++i){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(v,0);
        vector<int> dfsvis(v,0);
        for(int i=0;i<v;++i){
            if(!vis[i]){
                if(detectCycle(i,vis,dfsvis,adj)){
                    return true;
                }
            }
        }
        return false;
}

