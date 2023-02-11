// link - https://www.spoj.com/problems/PRATA/
// note - this problem is based on monotonic search space


#include <bits/stdc++.h>
using namespace std;

bool valid(long long t, long long rank[], long long int P, int n)
{
	long long cp = 0, tt, val, count = 0;
	
	for(int i = 0; i < n; i++)
	{
		tt = rank[i];
		count = 0;
		val = 1;
		
		while(tt <= t)
		{
			count++;
			val++;
			tt += (val*rank[i]);
		}
		
		cp += count;
		
		if(cp >= P) return true;
	}
	return false;
}

int main() 
{
	long long t, P, n;
	cin >> t;
	while(t--)
	{
		cin >> P >> n;
	
		long long rank[n];
	
		for(int i = 0; i < n; i++)
			cin >> rank[i];
		
		long long low = 1, high = INT_MIN;
	
		for(int i = 0; i < n; i++)
			high = max(high, rank[i]*(P*(P+1)/2));
	
		long long ans = 0;
		
		while(low <= high)
		{
			long long mid = low + (high -low)/2;
			
			if(valid(mid, rank, P, n))
			{
				ans = mid;
				high = mid-1;
			}
			else 
				low = mid + 1;
		}
	
		cout << ans << endl;
	}
	
	return 0;
}
