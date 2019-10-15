#include<stdio.h>

long long int m = 1000000007, i;

long long int fact[2000010];

long long int mod(long long int a, long long int b){
	
	long long int ans = 1;
	
	a %= m;
	
	while(b>0){
		if(b%2==1)
			ans = (a*ans) % m;
		
		b /= 2;
		a  = (a*a)%m;
	}
	
	return ans%m;
	
}

long long int help(long long int x, long long int y){
	
	long long int ans = ((((fact[x+y]%m)*mod(fact[x], m-2))%m)*((mod(fact[y], m-2)%m)%m))%m;
	return ans;
}

int main(){
	long long int t;
	scanf("%lld", &t);	
	
	long long int x, y;
	
	fact[0] = 1;
	for(i = 1; i<=2000000; i++){
		fact[i] = (fact[i-1]%m)*(i%m);
		fact[i] = fact[i] % m;
	}
	
	while(t--){
		
		scanf("%lld%lld", &x, &y);
		
		x = x%m;
		y = y%m;
		
		long long int ans = help(x, y);
		
		printf("%lld\n", ans);
	}
}
