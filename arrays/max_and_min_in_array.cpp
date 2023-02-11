void solve(){
	int n;
	cin>>n;
	int mx=INT_MIN,mn=INT_MAX;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		mx=max(mx,x);
		mn=min(mn,x);
	}
	cout<<mx<<" "<<mn<<endl;
}

