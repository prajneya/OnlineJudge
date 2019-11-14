#include<stdio.h>

long long int i, j, l;

long long int mat[105][105], a[105], c[105];

void multiply(long long int blah[105][105], long long int k, long long int m){

	long long int res[105][105];
	for(i = 0; i < k; i++) { 
        for(j = 0; j < k; j++) { 
            res[i][j] = 0; 
            for(l = 0; l < k; l++) 
                res[i][j] += ((mat[i][l]%m)* (blah[l][j]%m))%m; 
        } 
    }
    
    for(i = 0; i<k; i++){
    	for(j = 0; j<k; j++){
    		mat[i][j] = res[i][j]%m;
		}
	}
}

long long int power(long long int n, long long int k, long long int m){
	
	long long int temp[105][105];
	
	for(i = 0; i<k; i++){
		for(j = 0; j<k; j++){
			if(i==0)
				temp[i][j] = c[j];
			else
				temp[i][i-1] = 1;
			
		}
	}
	
	if(n==1){
		long long int sum = 0;
		for(i = 0; i<k; i++){
			sum += ((mat[0][i]%m)*(a[k-i-1]%m))%m;
		}
		return sum%m;
	}
	
	power(n/2, k, m);
	
	multiply(mat, k, m);
	if(n%2!=0)
		multiply(temp, k, m);
		
	long long sum = 0;
	for(i = 0; i<k; i++){
		sum += ((mat[0][i]%m)*(a[k-i-1]%m))%m;
	}
	
	return sum%m;
	
}

long long int help(long long int n, long long int k, long long int m){
	if(n==0)
		return 0;
	if(n<=k)
		return a[n-1];
	return power(n-k, k, m);
}

int main(){
	long long int n, k, m;
	scanf("%lld%lld%lld", &n, &k, &m);
	
	for(i = 0; i<k; i++){
		scanf("%lld", &c[i]);
	}
	for(i = 0; i<k; i++){
		scanf("%lld", &a[i]);
	}
	
	for(i = 0; i<k; i++){
		for(j = 0; j<k; j++){
			if(i==0)
				mat[i][j] = c[j];
			else
				mat[i][i-1] = 1;
			
		}
	}
	
	/*for(i = 0; i<k; i++){
		for(j = 0; j<k; j++){
			printf("%lld ", mat[i][j]);
			
		}
		printf("\n");
	}*/
	
	long long int ans = help(n, k, m)%m;
	
	/*for(i = 0; i<k; i++){
		for(j = 0; j<k; j++){
			printf("%lld ", mat[i][j]);
			
		}
		printf("\n");
	}*/
	
	printf("%lld", ans);
}
