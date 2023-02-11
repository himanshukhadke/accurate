// link https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        int major=a[0];
        int count=1;
        for(int i=1;i<n;++i){
            if(a[i]==major){
                ++count;
            }else{
                count--;
            }
            if(count==0){
                major=a[i];
                count=1;
            }
        }
       int ans=0;
       for(int i=0;i<n;++i){
           if(a[i]==major)ans++;
       }
       if(ans>n/2) return major;
       return -1;
    }
};
