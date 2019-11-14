#include<stdio.h>

long long int i, j, k, n;

double dp[301][301][301];

//double sum;
//long long int count = 0;

double help(long long int a, long long int b, long long int c){
	if(a<0 || b<0 || c<0)
		return 0;
	
	if(a==0 && b==0 && c==0){
		return dp[a][b][c] = 0;
		//count++;
	}
		
	if(dp[a][b][c]>=0){
		return dp[a][b][c];
		/*count++;
		sum+=dp[a][b][c];
		printf("REMEMBERING>> %lld %lld %lld : %0.9f\n", a, b, c, sum);
		return;*/
	}
		
	return dp[a][b][c] = (double) ( (double) n/ (double) (a+b+c) ) + (double) (( (double) a/ (double) (a+b+c))*help(a-1, b, c) ) + (double) (( (double) b/ (double) (a+b+c))*help(a+1, b-1, c) ) + (double) (( (double) c/ (double) (a+b+c))*help(a, b+1, c-1));
		
		
}

int main(){
	scanf("%lld", &n);
	
	long long int x;
	
	long long int c1 = 0, c2 = 0, c3 = 0;
	
	for(i = 0; i<n; i++){
		scanf("%lld", &x);
		if(x==1)
			c1++;
		else if(x==2)
			c2++;
		else
			c3++;
	}
	
	//printf("%lld %lld %lld\n", c1, c2, c3);
	
	for(i = 0; i<301; i++)
		for(j = 0; j<301; j++)
			for(k = 0; k<301; k++)
				dp[i][j][k] = -1;
	
	double ans = help(c1, c2, c3);
	/*printf("%0.6f\n", sum); 
	double ans = sum/count;*/
	printf("%0.6f\n", ans);
	
	
}
