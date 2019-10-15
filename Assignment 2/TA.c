#include<stdio.h>

int main(){
	
	long long int n;
	
	
	scanf("%lld", &n);
	
	long long int a[n+1];
	
	long long int i;
	for(i = 0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	
	
	long long int ans = 0;
	
	long long int pre[n], suff[n];
	
	pre[0] = a[0];
	for(i = 1; i<n; i++){
		pre[i] = pre[i-1] + a[i];
	}
	
	suff[n-1] = a[n-1];
	for(i = n-2; i>=0; i--){
		suff[i] = suff[i+1] + a[i];
	}
	
	long long int sum = pre[n-1];
	if(sum%3!=0){
		printf("0\n");
		return 0;
	}
	
	long long int smark[n];
	long long int j = 0;
	for(i = 0; i<n; i++){
		if(suff[i]==sum/3){
			smark[j] = i;
			j++;
		}
	}
	
	for(i = 0; i<n; i++){
		if(pre[i]==sum/3){
			
			long long int l = 0, r = j-1;
			long long int mid = l+(r-l)/2;
			
			long long final = -1;
			
			while(r>=l){
				if(smark[mid] <= (i+1)){
					l = mid+1;
					mid = l+(r-l)/2;
				}
				else if(smark[mid] > (i+1) && mid == 0){
					final = mid;
					break;
				}
				else if(smark[mid] > (i+1) && smark[mid-1] <= (i+1)){
					final = mid;
					break;
				}
				
				else{
					r = mid-1;
					mid = l+(r-l)/2;
				}
			}
			
			if(final!=-1){
				ans+=j-final;
			}
		}
	}
	
	printf("%lld", ans);
	
	return 0;
	
}
