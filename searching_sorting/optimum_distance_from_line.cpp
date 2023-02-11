// link - https://practice.geeksforgeeks.org/problems/optimum-location-of-point-to-minimize-total-distance/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#define EPS 1e-6

double getY(tuple<int,int,int>&l,double x){
    int a=get<0>(l);
    int b=get<1>(l);
    int c=get<2>(l);
    return -((a*x)+c)/b;
}

double caldist(double x,double y,double a,double b){
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

double compute(double x,tuple<int,int,int>&l,vector<pair<int,int>>&p,int n){
    double dist=0;
    double y=getY(l,x);
    for(int i=0;i<n;++i){
        dist+=caldist(x,y,p[i].first,p[i].second);
    }
    return dist;
}


class Solution{
    public:
    
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    double s=-1e6;
	    double e=1e6;
	    // loop while value  (e-s) > 0.1 
	    while((e-s) > EPS){
	       // cout<<e-s<<endl;
	        double mid1=s+(e-s)/3;
	        double mid2=e-(e-s)/3;
	        double dist1=compute(mid1,l,p,n);
	        double dist2=compute(mid2,l,p,n);
	        if(dist1<dist2){
	            e=mid2;
	        }else
	            s=mid1;
	    }
	    return compute((s+e)/2,l,p,n);
	    
    }
};
