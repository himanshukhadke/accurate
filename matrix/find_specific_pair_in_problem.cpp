// Suffix Sum of Matrix IMP

// link - https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

/*
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
*/

void solve(){
	int n=5;
	int mat[n][n] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }};
  	int maxMat[n][n];
  	int maxv=mat[n-1][n-1];
  	maxMat[n-1][n-1]=maxv;
  	// filling last row
  	for(int i=n-2;i>=0;--i){
  		maxv=max(maxv,mat[n-1][i]);
  		maxMat[n-1][i]=maxv;
  	}
  	// filling first column 
  	maxv=mat[n-1][n-1];
  	for(int i=n-2;i>=0;--i){
  		maxv=max(maxv,mat[i][n-1]);
  		maxMat[i][n-1]=maxv;
  	}

  	for(int i=n-2;i>=0;--i){
  		for(int j=n-2;j>=0;--j){
  			maxv=max(maxv,maxMat[i+1][j+1]-mat[i][j]);
  			maxMat[i][j]=max({maxMat[i+1][j+1],mat[i][j],maxMat[i+1][j],maxMat[i][j+1]});
  		}
  	}
  	cout<<maxv<<endl;
}	
