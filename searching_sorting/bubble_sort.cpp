// Bubble sort link - https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article 


#include <bits/stdc++.h>
using namespace std;

//bubble sort

class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        for(int i=0;i<n;++i){
	    	for(int j=0;j<n-i-1;++j){
	   	    	if(arr[j+1]<arr[j]){
		       		swap(arr[j+1],arr[j]);
		    	}
		    }
    	}
    }
};

