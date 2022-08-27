// Created by Himanshu Khadke
#include<bits/stdc++.h>
#define Fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define endl "\n"
#define mod7 1000000007
#define ff first
#define ss second
using namespace std;
int grid[1001][1001];

bool dfs(int cur,vector<int>& vis,int parent,unordered_map<int,vector<int>>& graph){
	vis[cur]=1;
	for(auto i:graph[cur]){
		if(!vis[i]){
			if(dfs(i,vis,cur,graph))
				return true;
		}else if(i!=parent){
			return true;
		}
	}
	return false;
}

void solve(){
    vector<pair<int,int>> edges =
    {	{0, 1}, {0, 6}, {0, 7}, {1, 2}, {1, 5}, {2, 3},
        {2, 4}, {7, 8}, {7, 11}, {8, 9}, {8, 10}, {10, 11}
    };
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<edges.size();++i){
    	graph[edges[i].first].push_back(edges[i].second);
    	graph[edges[i].second].push_back(edges[i].first);
    }
    vector<int> vis(12,0);
    cout<<dfs(0,vis,-1,graph);
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

