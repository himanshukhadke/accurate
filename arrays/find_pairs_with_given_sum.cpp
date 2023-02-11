// link - https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1 

 int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]]++;
        }
        int count=0;
        for(int i = 0 ; i < n ; i++){
            int target =  k-arr[i];
            if(mp.find(target)!= mp.end()){
                mp[arr[i]]--;
                count+=mp[target];
            }
        }
        return count;
    }
