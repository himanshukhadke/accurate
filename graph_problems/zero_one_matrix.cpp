class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> min(n,vector<int>(m,0));
        int ans=0;
        int x[]={1,0,-1,0};
        int y[]={0,1,0,-1};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                }else if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            min[i][j]=steps;
            ans=max(steps,ans);
            for(int k=0;k<4;++k){
                int row=i+x[k];
                int col=j+y[k];
                if(row>=0 and col>=0 and row<n and col<m and !vis[row][col]){
                    vis[row][col]=1;
                    q.push({{row,col},steps+1});
                }
            }
        }
         for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==0){
                    return -1;
                }
            }
        }
        return ans;
    }
};
