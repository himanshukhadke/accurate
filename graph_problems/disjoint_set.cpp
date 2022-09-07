// Created by Himanshu Khadke
#include<bits/stdc++.h>
#define Fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define endl "\n"
#define mod7 10e17
#define ff first
#define ss second
using namespace std;
int parent[100000];
int rank[100000];

/**
 * Disjoint set is a data structure use to find if two elements are in same set or not.
 * 
 * It also merges two set in constant time.
*/


void makeset(int k){
	for(int i=1;i<=k;++i)
		parent[i]=i,rank[i]=0;
}

int findPar(int node){
	if(parent[node]!=node)
		parent[node] = findPar(parent[node]);
	return node;
}

void unionn(int u,int v){
	u=findPar(u);
	v=findPar(v);
	if(rank[u]>rank[v])
		parent[v]=u;
	else if(rank[v]>rank[u])
		parent[u]=v;
	else{
		parent[u]=v;
		rank[v]++;
	}
}

void solve(){
	makeset();
	int m;
	cin>>m;
	while(m--){
		cin>>u>>v;
		unionn(u,v);
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

