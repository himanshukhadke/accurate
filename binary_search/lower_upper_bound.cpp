/**
note

upper_bound: first element which is strictly greater than the key
	when we found the element which is lower than or equal to key we just continue to search in right direction 
	if we found the element which is strictly greater than the key we store is as possible ans and try to find if there any ans exist
	in the left part of the array 

lower_bound: first element which is greater or equal to the key 
	when we found the element which is greater than or equal to key we store that element as possible answer and try to find if answer 
	exists in left part of the array.


*/

#include <bits/stdc++.h>
using namespace std;

void low_bound(int arr[],int key,int n){
    int s=0,e=n-1;
    int ans=-1;
    cout<<s<<" "<<n<<endl;
    while(s<=e){
        cout<<"hello"<<endl;
        int mid=(s+e)/2;
        cout<<mid<<endl;
        
        // upper bound founds element who is strictly greater than the key 
        if(arr[mid]<=key){
            s=mid+1;
        }else{
            ans=mid;
            e=mid-1;
        }
        
        // lower_bound founds element who is greater than or equal to key 
        // if(arr[mid]>=key){
        // 	ans=mid;
        // 	e=mid-1;
        // }else{
        // 	s=mid+1;
        // }
        
    }
    cout<<ans<<endl;
}

int main() {
    int a[]={1,2,5,8,8,8,8,8,10,12};
    int n=sizeof(a)/sizeof(int);
    low_bound(a,8,n);
    return 0;
}
