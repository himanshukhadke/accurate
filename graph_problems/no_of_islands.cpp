// Created by Himanshu Khadke
//https://www.techiedelight.com/count-the-number-of-islands/
#include<bits/stdc++.h>
#define Fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define endl "\n"
#define mod7 1000000007
#define ff first
#define ss second
using namespace std;

void visit(int i,int j,int n,int m,vector<vector<int>>& vis){
	queue<pair<int,int>> q;
	int x[]={1,0,-1,0,1,1,-1,-1};
    int y[]={0,1,0,-1,1,-1,1,-1};
    vis[i][j]=1;
    q.push({i,j});
    while(!q.empty()){
    	i=q.front().first;
    	j=q.front().second;
    	// int steps=q.front().second;
    	// if(j==m-1){
    	// 	ans=min(ans,steps);
    	// }
    	// dis[i][j]=steps;
    	q.pop();
    	for(int k=0;k<8;++k){
    		int row=i+x[k];	
    		int col=j+y[k];
    		if(row>=0 and col>=0 and row<n and col<m and !vis[row][col]){
    			vis[row][col]=1;
    			q.push({row,col});
    		}
    	}
    }
}

void solve(){
	vector<vector<int>> mat =
    {
        { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
        { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
    };
    // pair<int, int> src = make_pair(0, 0);
    // pair<int, int> dest = make_pair(7, 5);
    int n=mat.size();
    int m=mat[0].size();
    // vector<vector<int>> dis(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<pair<int,int>> unvisited;
    
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		if(mat[i][j]==0){
    			vis[i][j]=1;
    		}else{
    			unvisited.push_back({i,j});
    		}
    	}
    }

    
    int ans=0;
    for(int i=0;i<unvisited.size();++i){
    	int x=unvisited[i].ff;
    	int y=unvisited[i].ss;
    	if(!vis[x][y]){
    		++ans;
    		visit(x,y,n,m,vis);
    	}
    }
    cout<<ans<<endl;
    // cout<<"shortest distance of for all destinations from source "<<ans<<"\n";
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		cout<<vis[i][j]<<" ";
    	}
    	cout<<'\n';
    }
}
 
 
 
int32_t  main(){
	Fastio
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
