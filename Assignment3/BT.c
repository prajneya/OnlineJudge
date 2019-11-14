#include<stdio.h>

long long int i, j, l;

long long int m = 1000000007;

long long int mat[102][102], a[102];
long long int temp[102][102];

long long int res[102][102];
	
void multiply(long long int blah[102][102], long long int k){

	for(i = 0; i < k; i++) { 
        for(j = 0; j < k; j++) { 
            res[i][j] = 0; 
            for(l = 0; l < k; l++){
            	res[i][j] += ((mat[i][l]) * (blah[l][j]))%m; 
            	res[i][j] %=m;
			}
                
        } 
    }
    
    for(i = 0; i<k; i++)
    	for(j = 0; j<k; j++)
    		mat[i][j] = res[i][j];
}

long long int power(long long int n, long long int k){
	if(n==1){
		long long int sum = 0;
		for(i = 0; i<k; i++){
			sum += ((mat[0][i])*(a[k-i]))%m;
			sum%=m;
		}
		return sum;
	}
	
	power(n/2, k);
	
	multiply(mat, k);
	if(n%2!=0)
		multiply(temp, k);
		
	long long sum = 0;
	for(i = 0; i<k; i++){
		sum += ((mat[0][i])*(a[k-i]))%m;
		sum%=m;
	}
	
	return sum;
	
}

long long int help(long long int n, long long int k){
		
	for(i = 0; i<k; i++){
		for(j = 0; j<k; j++){
			if(i==0)
				temp[i][j] = 0;
			else
				temp[i][i-1] = 1;
			
		}
	}
	
	temp[0][0] = 1;
	temp[0][k-1] = 1;
	
	if(n==0)
		return 0;
	if(n<=k)
		return a[n];
	return power(n-k, k);
}

int main(){
	long long int n, k;
	scanf("%lld%lld", &n, &k);
	
	if(n==k){
		printf("2");
		return 0;
	}
	else if(n<k){
		printf("1");
		return 0;
	}
	else{
		for(i = 0; i<k; i++){
			for(j = 0; j<k; j++){
				if(i==0)
					mat[i][j] = 0;
				else
					mat[i][i-1] = 1;
			
			}
		}
	
		mat[0][0] = 1;
		mat[0][k-1] = 1;
		
		a[1] = 1;
		for(i = 2; i<k; i++){
			a[i] = 1;
		}
		a[k] = 2;
	
		/*for(i = 0; i<k; i++){
			for(j = 0; j<k; j++){
				printf("%lld ", mat[i][j]);
			
			}
			printf("\n");
		}*/
	
		long long int ans = help(n, k)%m;
	
		/*for(i = 0; i<k; i++){
			for(j = 0; j<k; j++){
				printf("%lld ", mat[i][j]);
			
			}
			printf("\n");
		}*/
	
		printf("%lld", ans);
	}
	
	
}
