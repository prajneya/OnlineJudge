#include<stdio.h>

long long int mat[2005][2005];
long long int prec[2005][2005];
long long int prer[2005][2005];
long long int sum[2005][2005];

long long int i, j;

int main(){
	long long int N, M, n, m;
	scanf("%lld%lld%lld%lld", &N, &M, &n, &m);
	
	long long int sumc = 0;
	
	for(i = 0; i<N; i++){
		sumc = 0;
		for(j = 0; j<M; j++){
			scanf("%lld", &mat[i][j]);
			sumc+=mat[i][j];
			prec[i][j] = sumc;
			if(i==0)
			prer[0][j] = mat[0][j];
			else
				prer[i][j] = prer[i-1][j]+mat[i][j];
		}
	}
	
	for(i = 0; i<N; i++){
		for(j = 0; j<M; j++){
			if(i == 0)
				sum[i][j] = prec[i][j];
			else{
				sum[i][j] = sum[i-1][j]+prec[i][j];
			}
		}
	}
	
	long long int max = -1;
	
	for(i = n-1; i<N; i++){
		for(j = m-1; j<M; j++){
			
			long long int temp;
			long long int x = 0, y = 0, z = 0;
			
			if(i-n>=0)
				x = sum[i-n][j];
			
			if(j-m>=0)
				y = sum[i][j-m];
				
			if(i-n>=0 && j-m>=0)
				z = sum[i-n][j-m];
				
			temp = sum[i][j] - x - y + z;
			if(temp>max)
				max = temp;
		}
	}
	
	printf("%lld\n", max);
	
	/*for(i = 0; i<N; i++){
		for(j = 0; j<M; j++){
			printf("%lld ", sum[i][j]);
		}
		printf("\n");
	}*/
	
}
