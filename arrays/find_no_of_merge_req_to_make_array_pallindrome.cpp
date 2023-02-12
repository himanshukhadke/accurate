//https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
/*
sample input
4 -> testcases
3
15 4 15 
4
1 4 5 1
4
11 14 15 99 
1
12

sample output 
0
1
3
0

*/

void find_no_of_merge(){
	int n;
	cin>>n;	
	vector<int> arr(n);
	for(int &i:arr){cin>>i;}
	int merge=0;
	if(n<2){ 
		cout<<0<<endl;
		return;
	}	
	for(int i=0,j=n-1;i<j;){
		if(arr[i]==arr[j]){
			++i,--j;
		}else if(arr[i]>arr[j]){
			merge++;
			arr[j-1]+=arr[j];
			--j;
		}else {
			merge++;
			arr[i+1]+=arr[i];
			++i;
		}
	}
	cout<<merge<<endl;
}
