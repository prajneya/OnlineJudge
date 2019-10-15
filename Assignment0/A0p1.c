#include<stdio.h>

int main(){
	long int a, b;
	if(scanf("%ld%ld", &a, &b)!=1){
		long sum = a+b;
		long diff = a-b;
		long pro = a*b;
		long quo = a/b;
		long rem = a%b;
	
		double pre = (double) a / b;
	
		printf("%ld ", sum);
		printf("%ld ", diff);
		printf("%ld ", pro);
		printf("%ld ", quo);
		printf("%ld ", rem);
		printf("%0.10lf ", pre);
		return 0;
	}
	else{
		printf("FAILED");
		return 0;
	}
	
	
}
