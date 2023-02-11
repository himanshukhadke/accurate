
//  this is a dp problem 
// link - https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

// top down dp solution 
class Solution
{
    public:
    int dp[10000]={0};
    int ans(int arr[],int n,int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int x=ans(arr,n,i+1);
        int y=arr[i]+ans(arr,n,i+2);
        return dp[i]=max(x,y);
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {   
        memset(dp,-1,sizeof(dp));
        return ans(arr,n,0);
    }
};

// bottom up dp using array find editorial for understanding 
class Solution
{
    public:
    int dp[10000][2];
    int ans(int arr[],int n,int i){
        if(i>=n){
            return 0;
        }
        int x=ans(arr,n,i+1);
        int y=arr[i]+ans(arr,n,i+2);
        return max(x,y);
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {   
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i){
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=dp[i-1][0]+arr[i-1];
        }
        return max(dp[n][0],dp[n][1]);
    }
};
