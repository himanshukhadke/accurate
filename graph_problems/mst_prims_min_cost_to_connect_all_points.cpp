//https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int keys[n];
        bool mst[n];
        int parent[n];
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        for(int i=0;i<n;++i)
            keys[i]=INT_MAX,mst[i]=false,parent[i]=-1;
        set<pair<int,int>> s;
        s.insert({0,0});
        keys[0]=0;
        while(!s.empty()){
            int u=s.begin()->second;
            mst[u]=true;
            s.erase(s.begin());
            for(auto it:adj[u]){
                int v=it.first;
                int w=it.second;
                if(!mst[v] and keys[v]>w){
                    s.erase({keys[v],v});
                    keys[v]=w;
                    parent[v]=0;
                    s.insert({w,v});
                }
            }
        }
        int sum=0;
        for(int i:keys)
            sum+=i;
        return sum;
    }
};
