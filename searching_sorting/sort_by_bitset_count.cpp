// link - https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

// using stable_sort() stl function 
class Solution{
    public:
    
    bool static cal(int i,int j){
        int a=__builtin_popcount(i);
        int b=__builtin_popcount(j);
        if(a>b){
            return true;
        }
        return false;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr,arr+n,cal);
    }
};


// using multimap 
// multimap sort the values inside but keep the order of keys as it is if they are equal 

class Solution{
    public:
    
    void sortBySetBitCount(int arr[], int n)
    {
        multimap<int,int,greater<int>> mp;
        for(int i=0;i<n;++i){
            int set_bits = __builtin_popcount(arr[i]);
            mp.insert({set_bits,arr[i]});
        }
        int i=0;
        for(auto it : mp){
            arr[i++]=it.second;
        }
    }
};


/**
Method 3: Counting Sort based

This problem can be solved in O(n) time. The idea is similar to counting sort.

Note: There can be a minimum 1 set-bit and only a maximum of 31set-bits in an integer.

Steps (assuming that an integer takes 32 bits):

Create a vector “count” of size 32. Each cell of count i.e., count[i] is another vector that stores all the elements whose set-bit-count is i
Traverse the array and do the following for each element:
Count the number set-bits of this element. Let it be ‘setbitcount’
count[setbitcount].push_back(element)
Traverse ‘count’ in reverse fashion(as we need to sort in non-increasing order) and modify the array.
*/
