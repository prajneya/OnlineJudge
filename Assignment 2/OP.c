#include<stdio.h>
#include<math.h>

long long int sum[2005];

void fill(){
	long long int i;
	for(i = 1; i<=2000; i++){
		sum[i] = sum[i-1] + (2*i*i)-(2*i)+1; 
		//printf("%lld ", sum[i]);
	}
	
}

long long int help(long long int n){
	long long int l = 1, r = n;
	long long int mid = l + ((r-l)/2);
		
	long long ans = -1;
		
	while(r>=l){
		if(sum[mid]>n && sum[mid-1]<=n){
			ans = mid-1;
			break;
		}
		else if(sum[mid]>n && sum[mid-1]>n){
			r = mid-1;
			mid = l + ((r-l)/2);
		}
		else if(sum[mid]==n){
			ans = mid;
			break;
		}
		else if(sum[mid]<n){
			l = mid+1;
			mid = l + ((r-l)/2);
		}
	}
	
	return ans;
	
}

int main(){
	long long int t;
	scanf("%lld", &t);
	
	fill();
	
	while(t--){
		long long int n;
		scanf("%lld", &n);
	    //printf("%lld and %f\n", final, g);
		long long int ans = help(n);
		printf("%lld\n", ans);
		
	}
}
