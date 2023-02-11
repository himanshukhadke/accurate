// link - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        for(int i=0;i<n;++i){
            int k=abs(arr[i]);
            if(arr[k-1]<0){
                ans[0]=k;
            }else
                arr[k-1]*=-1;
        }
        
        for(int i=0;i<n;++i){
            if(arr[i]>0){
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
};
