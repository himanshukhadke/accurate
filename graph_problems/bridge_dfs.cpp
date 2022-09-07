class Solution {
public:
    int timer=0;
    vector<pair<int,int>> finally;
    void dfs(int node,vector<int>& disc,vector<int>& mindisc,vector<int>& vis,vector<vector<int>>& adj,int parent){
        vis[node]=1;
        disc[node]=mindisc[node]=++timer;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,disc,mindisc,vis,adj,node);
                mindisc[node]=min(mindisc[node],mindisc[it]);
                if(disc[node]<mindisc[it]){
                    finally.push_back({it,node});
                }
            }else{
                mindisc[node]=min(mindisc[node],disc[it]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;++i){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> disc(n,-1);
        vector<int> mindisc(n,-1);
        vector<int> vis(n,0);
        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(i,disc,mindisc,vis,adj,-1);
            }
        }
        int k=finally.size();
        vector<vector<int>> ans(k);
        for(int i=0;i<k;++i){
            ans[i].push_back(finally[i].first);
            ans[i].push_back(finally[i].second);
        }
        return ans;
    }
};
