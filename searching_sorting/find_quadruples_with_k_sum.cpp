//  link - https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1


class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int a,b,c,d;
        int temp=k;
        set<vector<int> > ans;
        for(int i=0;i<n-3;++i){
            for(int j=i+1;j<n-2;++j){
                int s=j+1;
                int e=n-1;
                // cout<<"temp "<<endl;
                while(s<e){
                    if(arr[i]+arr[j]+arr[s]+arr[e]<k){
                        s++;
                    }else if(arr[i]+arr[j]+arr[s]+arr[e]>k){
                        e--;
                    }else{
                        vector<int> t={arr[i],arr[j],arr[s],arr[e]};
                        sort(t.begin(),t.end());
                        ans.insert(t);
                        s++,e--;
                    }
                }
            }
        }
        vector<vector<int> > realans;
        for(auto m:ans){
            realans.push_back(m);
        }
        return realans;
    }
};
