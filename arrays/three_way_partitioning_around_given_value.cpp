// link - https://practice.geeksforgeeks.org/problems/three-way-partitioning/1


    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // dutch national flag algorithm.
        int i=0; // idx of values strictly lower than a.
        int j=0; // idx of values greater than a and lower than b (a<=ele and ele<=b).
        int k=arr.size()-1; // idx of values strictly greater than b.
        while(j<=k){
            if(arr[j]<a){
                swap(arr[i++],arr[j++]);
            }else if(arr[j]>=a and arr[j]<=b){
                ++j;
            }else {
                swap(arr[j],arr[k--]);
            }
        }
    }
