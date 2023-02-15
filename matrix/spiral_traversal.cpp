// link - https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
     int m=r;
     int n=c;
     vector<int> arr;
     int row=0;
     int col=-1;
     while(true){
         for(int i=0;i<n;++i){
             cout<<matrix[row][++col]<<" "; 	 // traversed a row
         }	
         if(--m==0){break;}			// decrement row count
         for(int i=0;i<m;++i){
             cout<<matrix[++row][col]<<" ";	// traverse last column
         }
         if(--n==0){break;}			// decrement column count 
         for(int i=0;i<n;++i){
             cout<<matrix[row][--col]<<" ";	// traverse last row
         }
         if(--m==0){break;}   			// decrement row count
         for(int i=0;i<m;++i){
             cout<<matrix[--row][col]<<" ";	// traverse first col
         }
         if(--n==0){break;}			// decrement column count 
     }
     return arr;
    }
};
