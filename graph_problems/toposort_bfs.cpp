class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> topo;
	    vector<int> in(V,0);
	    for(int i=0;i<V;++i){
	        for(auto k:adj[i])
	            in[k]++;
	    }
	    for(int i=0;i<V;++i){
	        if(in[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int top=q.front();
	        q.pop();
	        topo.push_back(top);
	        for(auto i:adj[top]){ 
	            --in[i];
	            if(in[i]==0)     //check if all dependancies are ended
	                q.push(i);    // if ended the push it into stack and traverse the nodes dependant on that node
	        }
	    }
	    return topo;
	}
};
