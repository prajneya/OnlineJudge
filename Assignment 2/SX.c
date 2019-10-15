#include<stdio.h>
#include<math.h>

int main(){
	long long int n;
	scanf("%lld", &n);
	
	long long int x[n+2], y[n+2];
	
	long long int minx = 1000005, miny = 1000005, maxx = -1000005, maxy = -1000005;
	
	long long int per = 0, i;
	
	for(i = 0; i<n; i++){
		scanf("%lld%lld", &x[i], &y[i]);
		if(x[i]<minx)
			minx = x[i];
		if(x[i]>maxx)
			maxx = x[i];
		if(y[i]<miny)
			miny = y[i];
		if(y[i]>maxy)
			maxy = y[i];
	}
	
	long long int imp_per = 2*(maxx-minx);
	imp_per += 2*(maxy-miny);
	
	//printf("%lld\n", imp_per);
	
	
	for(i = 1; i<n; i++){
		if(x[i]==x[i-1])
			per+=fabs(y[i]-y[i-1]);
		else
			per+=fabs(x[i]-x[i-1]);
			
		//printf("per increased by %lld\n", per);
	}
	
	if(x[n-1]==x[0])
		per+=fabs(y[n-1]-y[0]);
	else
		per+=fabs(x[n-1]-x[0]);
		
	long long int ans = per-imp_per;
	
	//printf("%lld\n", per);
	printf("%lld\n", ans);
	
}
