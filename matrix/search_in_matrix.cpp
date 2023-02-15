// link - https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
          return false;
        int n=matrix.size(); // no of rows
        int m=matrix[0].size(); // no of columns
        int s=0;
        int e=n*m-1;
        while(s<=e){
            int mid=(s+e)/2;
            int row=mid/m;
            int col=mid%m; 
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return false;
    }
};
