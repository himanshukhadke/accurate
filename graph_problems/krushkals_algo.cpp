
// https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
public:
    int parent[100000];
    int rank[100000];

    void makeset(int v){
        for(int i=0;i<v;++i)
            parent[i]=i,rank[i]=0;
    }
    
    int findpar(int node){
        if(parent[node]!=node)
            return parent[node] = findpar(parent[node]);
        return node;
    }
    
    void unionn(int u,int v){
        u=findpar(u);
        v=findpar(v);
        if(rank[u]>rank[v])
            parent[v]=u;
        else if(rank[v]>rank[u])
            parent[u]=v;
        else {
            parent[u]=v;
            rank[v]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        set <pair<int,pair<int,int>>> s;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                s.insert({dist,{i,j}});
            }
        }
        makeset(n);
        int sum=0;
        while(!s.empty()){
            int w=s.begin()->first;
            int u=s.begin()->second.first;
            int v=s.begin()->second.second;
            s.erase(s.begin());
            if(findpar(u)!=findpar(v)){
                sum+=w;
                unionn(u,v);
            }
        }        
        return sum;
    }
};
