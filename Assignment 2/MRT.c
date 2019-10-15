#include<stdio.h>
#include<stdbool.h>

bool check(long long int x, long long int w, long long int free[], long long int s){
	
	long long int prev = free[0];
	long long int count = 1;
	long long int i;
	for(i = 1; i<s; i++){
		if(free[i]-prev>=x){
			count++;
			if(count==w){
				return true;
			}
			prev = free[i];
		}
	}
	return false;
	
}

int main(){
	long long int t;
	scanf("%lld", &t);
	
	long long int w, s;
	
	while(t--){
		scanf("%lld%lld", &w, &s);
		
		long long int free[s];
		
		long long int i;
		for(i = 0; i<s; i++){
			scanf("%lld", &free[i]);
		}
		
		long long int l = 0, r = free[s-1];
		long long int mid = l + ((r-l)/2);
		
		long long ans = -1;
		
		while(r>=l){
			if(check(mid, w, free, s)){
				if(mid>ans){
					ans = mid;
				}
				l = mid+1;
				mid = l + ((r-l)/2);
			}
			else{
				r = mid-1;
				mid = l + ((r-l)/2);
			}
		}
		
		printf("%lld\n", ans-1);
		
	}
}
