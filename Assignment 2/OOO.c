#include<stdio.h>

int main(){
	long long int t;
	scanf("%lld", &t);
	while(t--){
		long long int n;
		scanf("%lld", &n);
		
		long long int a[n];
		int flag[100000] = {0};
		
		long long int i, j;
		for(i = 0; i<n; i++){
			scanf("%lld", &a[i]);
		}
		
		long long int count = 0, index = -1;
		for(i = 0; i<n-1; i++){
			if(flag[i]==0){
				//printf("IM IN with %lld\n", a[i]);
				flag[i] = 1;
				for(j = i+1; j<n; j++){
					
					if(a[i]==a[j]){
						flag[j] = 1;
						count++;
					}
					//printf("CHECKING %lld with %lld: COUNT IS %lld\n", a[i], a[j], count);
					if(count==2){
						break;
					}
				}
				if(count == 0){
					index = i;
					break;
				}
			}
			//printf("---------------------\n");
			//printf("COUNT OF %lld is %lld\n", a[i], count);
			count = 0;
		}
		
		if(index==-1)
			index = n-1;
		
		printf("%lld\n", a[index]);
	}
}
