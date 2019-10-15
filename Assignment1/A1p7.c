#include<stdio.h>

int main(){
	long int n;
	if(scanf("%ld", &n)==1){
		if(n==1){
			printf("1\n");
			return 0;
		}
		else{
			long int ans = 2*(n-1);
			printf("%ld\n", ans);
			return 0;
		}
	}
	
}
