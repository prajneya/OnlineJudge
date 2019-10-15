#include<stdio.h>

int main(){
	long long int q;
	scanf("%lld", &q);
	
	while(q--){
		long long int l, r;
		scanf("%lld%lld", &l, &r);
		
		long long int ans = l, prev = 0;
		
		for(; ans<=r;){
			prev = ans | (ans+1);
			if(prev<=r)
				ans = prev;	
			else
				break;
		}
		
		printf("%lld\n", ans);
		
	}
}
