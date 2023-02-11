// link - https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

class Solution{
  public:
    int minJumps(int arr[], int n){
        int current=arr[0];
        int jump=1;
        int range=0;
        for(int i=1;i<n;++i){
            if(i>current) break; // we have exceeded the current range
            if(i==n-1) return jump; // reached to end 
            if(i<current){
              range=max(range,arr[i]+i);   // find maximum range of frome current range
            }else if(i==current){
              range=max(range,arr[i]+i); 
              current=range; // set the current range to maximum range
              range=0;
              ++jump;
            }
        }
        return -1;
    }
};
