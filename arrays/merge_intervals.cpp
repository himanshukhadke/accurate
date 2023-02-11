//link - https://leetcode.com/problems/merge-intervals/description/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& range) {
    vector<vector<int> > ans;
    sort(range.begin(),range.end());
	int flag=0,n=range.size();
	int s=range[0][0],e=range[0][1];
	for(int i=1;i<n;++i){
		int x=range[i][0];
		int y=range[i][1];
		if(y<e){ // full overlap with first 
			continue;
		}else if(x>e){	// not overlapping
			ans.push_back({s,e});
			s=x;
            e=y;
		}else {	 // overlapping
			e=y;
        }
	}
	ans.push_back({s,e});	
	return ans;
    }
};
