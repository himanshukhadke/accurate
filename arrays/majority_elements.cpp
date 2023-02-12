// link - https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/



    int countOccurence(int arr[], int n, int k) {
        if(k<2)
            return 0;
        pair<int,int> maj[k-1];
        for(int i=0;i<k-1;++i){
            maj[i].first=-1;
            maj[i].second=0;
        }
        
        for(int i=0;i<n;++i){
            int j;
            for(j=0;j<k-1;++j){
                if(arr[i]==maj[j].first){
                    ++maj[j].second;
                    break;
                }
            }
            if(j==k-1){
                int l;
                for(l=0;l<k-1;++l){
                    if(maj[l].second==0){
                        maj[l].first=arr[i];
                        maj[l].second=1;
                        break;
                    }
                }
            
                if(l==k-1){
                      for(int l=0;l<k-1;++l)
                           maj[l].second--;
                }
            }
        }
        set<int> s;
        for(int j=0;j<k-1;++j){
            int cnt=0;
            for(int i=0;i<n;++i){
                if(maj[j].first==arr[i]){
                    ++cnt;
                }
            }
            if(cnt>n/k) s.insert(maj[j].first);
        }
        return s.size();
    }
