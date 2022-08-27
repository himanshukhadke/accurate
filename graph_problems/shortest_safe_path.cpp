// Created by Himanshu Khadke
//https://www.techiedelight.com/find-shortest-safe-route-field-sensors-present/
#include<bits/stdc++.h>
#define Fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define endl "\n"
#define mod7 1000000007
#define ff first
#define ss second
using namespace std;
int grid[1001][1001];
 
void make_sensor_active(int i,int j,int n,int m,vector<vector<int>>& vis){
	if(i+1<n and j+1<m)vis[i+1][j+1]=1;
	if(i-1>=0 and j-1>=0) vis[i-1][j-1]=1;
	if(i-1>=0 and j+1<m) vis[i-1][j+1]=1;
	if(i+1<n and j-1>=0) vis[i+1][j-1]=1;
	if(i-1>=0)vis[i-1][j]=1;
    if(j-1>=0)vis[i][j-1]=1;
    if(j+1<m)vis[i][j+1]=1;
    if(i+1<n)vis[i+1][j]=1;
}

void solve(){
	vector<vector<int>> mat =
    {
 		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
    // pair<int, int> src = make_pair(0, 0);
    // pair<int, int> dest = make_pair(7, 5);
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dis(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>	q;
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		if(mat[i][j]==0){
    			vis[i][j]=1;
    			make_sensor_active(i,j,n,m,vis);
    		}
    		if(j==0 and !vis[i][j]){
    			q.push({{i,j},0});
    			vis[i][j]=1;
    			dis[i][j]=0;
    		}
    	}
    }

    int x[]={1,0,-1,0};
    int y[]={0,1,0,-1};
    int ans=INT_MAX;
    while(!q.empty()){
    	int i=q.front().first.first;
    	int j=q.front().first.second;
    	int steps=q.front().second;
    	if(j==m-1){
    		ans=min(ans,steps);
    	}
    	dis[i][j]=steps;
    	q.pop();
    	for(int k=0;k<4;++k){
    		int row=i+x[k];	
    		int col=j+y[k];
    		if(row>=0 and col>=0 and row<n and col<m and !vis[row][col]){
    			vis[row][col]=1;
    			q.push({{row,col},steps+1});
    		}
    	}
    }
    cout<<"shortest distance of for all destinations from source "<<ans<<"\n";
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		cout<<dis[i][j]<<" ";
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
