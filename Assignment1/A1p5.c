#include<stdio.h>

int main(){
	long long int n;
	if(scanf("%lld", &n)==1){
		long long int a[n];
		long long int i, j, k;
		long long int rem = 0;
		for(i = 0; i<n; i++){
			scanf("%lld", &a[i]);
		}
		long long int count = 0;
		for(i = 0; i<n; i++){
			
			count += a[i]/3;
			rem = a[i]%3;
			if(rem==0){
				continue;
			}
			else if(rem==1){
				for(j = i+1; j<n; j++){
					if(a[j]>=2){
						count++;
						a[j]-=2;
						break;
					}
				}
			}
			else{
				for(j = 1; j<=2; j++){
					for(k = i+1; k<n; k++){
						if(a[k]>=2){
							count++;
							a[k]-=2;
							break;
						}
					}
				}	
			}
		}
	
		printf("%lld", count);
		
	}
}
