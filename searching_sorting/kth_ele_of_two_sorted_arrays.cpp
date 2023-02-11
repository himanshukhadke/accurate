// link - https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1


    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int> p;
        
        for(int i=0;i<n;++i){
            p.push(arr1[i]);
            if(p.size()>k){
                p.pop();
            }
        }
        for(int i=0;i<m;++i){
            p.push(arr2[i]);
            if(p.size()>k){
                p.pop();
            }
        }
        return p.top();
    }
