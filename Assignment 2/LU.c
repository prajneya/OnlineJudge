#include<stdio.h>

long long int a[100005], sum[100005], start[1000005], end[1000005], inc[1000005], mul[1000005];
long long int n, q, i;

long long int hash_a = 0;
long long int m = 1000000007;

long long int negmod(long long int num){
	long long int ans = (num % m + m) % m;
	return ans;
}

void increase(){
	
	for(i = 0; i<q; i++){
		sum[start[i]] += (inc[i]%m);
		if((end[i]+1)<n){
			sum[end[i]+1] -= (inc[i]%m);
		}
	}
	
	a[0] += sum[0];
	
	for(i = 1; i<n; i++){
		sum[i] += sum[i-1];
		sum[i] %= m;
		a[i] += sum[i];
		a[i] %= m;
	}
}

void hash(){
	
	mul[0] = 1;
	for(i = 1; i<n; i++){
		mul[i] = mul[i-1]*107;
		mul[i] %= m;
	}
	
	
	for(i = 0; i<n; i++){
		a[i]%=m;
		if(hash_a<0)
			hash_a = negmod(hash_a);
		else
			hash_a %= m;
		//printf("HASH: %lld\n", hash_a);
		hash_a += (mul[i]*a[i]);
		//printf("HASH: %lld\n", hash_a);
		if(hash_a<0)
			hash_a = negmod(hash_a);
		else
			hash_a %= m;
	}
}

int main(){
	
	scanf("%lld%lld", &n, &q);
	
	for(i = 0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	
	for(i = 0; i<q; i++){
		scanf("%lld%lld%lld", &start[i], &end[i], &inc[i]);
	}
	
	increase();
	hash();
	
	/*printf("---------------\n");
	for(i = 0; i<n; i++){
		printf("%lld ", a[i]);
	}
	//printf("\n---------------\n");
	//printf("\n"); */
	
	printf("%lld\n", hash_a);
}
