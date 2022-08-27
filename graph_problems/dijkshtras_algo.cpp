// Created by Himanshu Khadke
#include<bits/stdc++.h>
#define Fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define endl "\n"
#define mod7 10e17
#define ff first
#define ss second
using namespace std;
vector<int> p(100001,-1);
vector<int> dis(100001,mod7);

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> graph(n+1);
	int a,b,w;
	for(int i=0;i<m;++i){
		cin>>a>>b>>w;
		graph[a].push_back({b,w});
		graph[b].push_back({a,w});
	}
	set<pair<int,int>> q;
	q.insert({0,1});
	dis[1]=0;
	while(!q.empty()){
		int v = q.begin()->second;
		if(v==n) break;
		q.erase(q.begin());
		for(auto edge:graph[v]){
			int u = edge.first;
			int w = edge.second;
			if( dis[u] > dis[v] + w){
				p[u]=v;
				q.erase({dis[u],u});
				dis[u] = dis[v] + w;
				q.insert({dis[u],u});
			}
		}
	}
	vector<int> path;
	// cout<<dis[n]<<endl;
	if(p[n]!=-1){
		path.push_back(n);
		for(int i=p[n];i!=-1;i=p[i]){
			path.push_back(i);
		}
		reverse(path.begin(),path.end());
	}else{
		cout<<-1<<endl;
		return;
	}
	for(auto i:path){
		cout<<i<<" ";
	}
	cout<<endl;
}
 
 
 
int32_t  main(){
	Fastio
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

