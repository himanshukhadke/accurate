class Solution{
    public:
    int X[4]={1,0,-1,0};
    int Y[4]={0,1,0,-1};
    
    void get(vector<vector<int>> &m, int n,vector<string>&ans,int i,int j,string s,vector<vector<int>>&vis){
        if(i<0 or j<0 or j>=n or i>=n or vis[i][j] or !m[i][j]){
            return;
        }
        //  cout<<i<<" "<<j<<" "<<s<<endl;
        if(i==n-1 and j==n-1){
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        for(int k=0;k<4;++k){
            int row=i+X[k];
            int col=j+Y[k];
            string temp=s;
            if(i>=0 and j>=0 and j<n and i<n){
                if(k==0)get(m,n,ans,row,col,temp+=('D'),vis);
                if(k==1)get(m,n,ans,row,col,temp+=('R'),vis);
                if(k==2)get(m,n,ans,row,col,temp+=('U'),vis);
                if(k==3)get(m,n,ans,row,col,temp+=('L'),vis);
            }
        }
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        get(m,n,ans,0,0,"",vis);
        if(ans.size()==0) ans.push_back("-1");
        return ans;
    }
};

