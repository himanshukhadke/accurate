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
 
 void printPath(unordered_map<int,int> & mp,int k){
 	cout<<k<<" ";
 	for(;mp[k]!=-1;k=mp[k]){
 		cout<<mp[k]<<" ";
 	}
 }


void solve(){
     unordered_map<int, int> ladder, snake;
	 ladder[1] = 38;
	 ladder[4] = 14;
	 ladder[9] = 31;
	 ladder[21] = 42;
	 ladder[28] = 84;
	 ladder[51] = 67;
	 ladder[72] = 91;
	 ladder[80] = 99;

	 snake[17] = 7;
	 snake[54] = 34;
	 snake[62] = 19;
	 snake[64] = 60;
	 snake[87] = 36;
	 snake[93] = 73;
	 snake[95] = 75;
	 snake[98] = 79;

	vector<int> dis(101,0);
	vector<int> vis(101,0);
	unordered_map<int,int> mp;
	queue<pair<int,int>> q;
	q.push({0,0});
	vis[0]=1;
	dis[0]=0;
	mp[0]=-1;
	while(!q.empty()){
		int k=q.front().first;
		int steps=q.front().second;
		dis[k]=steps;
		if(k==100){
			cout<<"Shortest distance from start is : "<<dis[k]<<'\n';
			printPath(mp,k);
			break;
		}
		q.pop();
		for(int i=1;i<=6;++i){
			int m=k+i;
			if(ladder[m]!=0 and !vis[ladder[m]]){
				mp[ladder[m]]=k;
				vis[ladder[m]]=1;
				q.push({ladder[m],steps+1});
				continue;
			}
			if(snake[m]!=0 and !vis[snake[m]]){
				mp[snake[m]]=k;
				vis[snake[m]]=1;
				q.push({snake[m],steps+1});
				continue;
			}
			if(!vis[m]){
				vis[m]=1;
				mp[m]=k;
				q.push({m,steps+1});
			}
		}
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

