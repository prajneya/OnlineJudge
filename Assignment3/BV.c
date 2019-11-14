#include<stdio.h>

long long int max(long long int a, long long int b){
	if(a>b)
		return a;
	return b;
}

long long int i;

int main(){
	long long int n;
	scanf("%lld", &n);
	long long int a[n], b[n];
	
	for(i = 0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	
	for(i = 0; i<n; i++){
		scanf("%lld", &b[i]);
	}
	
	long long int dp[n][3];
	
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = -1000001;
	
	long long int posa = a[0], posb=b[0], posc=-1000001;
	
	for(i = 1; i<n; i++){
		dp[i][0] = max(dp[i-1][0], 0)+a[i];
		dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]), 0)+b[i];
		dp[i][2] = max(max(dp[i-1][1], 0), dp[i-1][2])+a[i];
		
		if(posa<dp[i][0])
			posa = dp[i][0];
		if(posb<dp[i][1])
			posb = dp[i][1];
		if(posc<dp[i][2])
			posc = dp[i][2];
	}
	
	long long int ans = max(max(posa, posb), posc);
	
	printf("%lld", ans);
}
