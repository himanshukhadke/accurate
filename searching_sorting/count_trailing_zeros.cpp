// link - https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1



class Solution
{
    public:
        int check(int n){
            int x=5;
            int ans=0;
            while(n/x>0){
                ans+=(n/x);
                x*=5;
            }
            return ans;
        }
    
        int findNum(int n)
        {
            int s=1;
            int e=1e9;
            int ans=-1;
            while(s<=e){
                int mid=(s+e)/2;
                if(check(mid)>=n){
                    ans=mid;
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }
            return ans;
        }
};
