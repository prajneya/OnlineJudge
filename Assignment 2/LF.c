#include<stdio.h>
#include<string.h>

int ans[100000];


long long int multiply(long long int len, long long int mr){
	
	long long int carry = 0;
	
	long long int i, pro;
	for(i = 0; i<len; i++){
		pro = ans[i]*mr+carry;
		ans[i] = pro%10;
		carry = pro/10;
	}
	
	while(carry!=0){
		ans[len] = carry%10;
		carry/=10;
		len++;
	}
	
	return len;
	
}

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		
		long long int n;
		scanf("%lld", &n);
		
		long long int i;
		for(i = 0; i<100000; i++){
			ans[i] = 0;
		}
		
		ans[0] = 1;
		long long int len = 1;

		for(i = 2; i<=n; i++){
			len = multiply(len, i);
		}
		
		for(i = len-1; i>=0; i--){
			printf("%d", ans[i]);
		}
		printf("\n");
		
	}
}
