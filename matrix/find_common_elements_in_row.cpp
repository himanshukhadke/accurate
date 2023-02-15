// link - https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/


void solve(){
	int n=4;
	int m=5;
	int mat[n][m] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		if(mp[mat[i][j]]==i){
    			mp[mat[i][j]]=i+1;
    		}
    		if(i==n-1 && mp[mat[i][j]]==n){
    			cout<<mat[i][j]<<" ";
    		}
    	}
    }
    cout<<endl;
}
