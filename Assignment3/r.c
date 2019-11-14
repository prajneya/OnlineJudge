void removeAThree(long long int a, long long int b, long long int c, double sum);
void removeATwo(long long int a, long long int b, long long int c, double sum);
void removeAOne(long long int a, long long int b, long long int c, double sum);

void removeAThree(long long int a, long long int b, long long int c, double sum){
	if(c==0){
		removeATwo(a, b, c, sum);
		removeAOne(a, b, c, sum);
	}
		
	if(dp[a][b][c]!=0)
		sum+=dp[a][b][c];
		
	c--;
	b++;
	dp[a][b][c] = n/(a+b+c);
	sum+=dp[a][b][c];
	removeAThree(a, b, c, sum);
	removeATwo(a, b, c, sum);
	removeAOne(a, b, c, sum);
}

void removeATwo(long long int a, long long int b, long long int c, double sum){
	if(b==0 && c==0){
		removeAOne(a, b, c, sum);
	}
	else if(b==0){
		removeAThree(a, b, c, sum);
		removeAOne(a, b, c, sum);
	}
		
	if(dp[a][b][c]!=0)
		sum+=dp[a][b][c];
		
	b--;
	a++;
	dp[a][b][c] = n/(a+b+c);
	sum+=dp[a][b][c];
	removeAThree(a, b, c, sum);
	removeATwo(a, b, c, sum);
	removeAOne(a, b, c, sum);
}

void removeAOne(long long int a, long long int b, long long int c, double sum){
	if(a==0 && b==0 && c==0)
		return;
	
	else if(a==0 && b==0){
		removeAThree(a, b, c, sum);
	}
	else if(a==0){
		removeAThree(a, b, c, sum);
		removeATwo(a, b, c, sum);
	}
	
	if(dp[a][b][c]!=0)
		sum+=dp[a][b][c];
		
	a--;
	dp[a][b][c] = n/(a+b+c);
	sum+=dp[a][b][c];
	removeAThree(a, b, c, sum);
	removeATwo(a, b, c, sum);
	removeAOne(a, b, c, sum);
}

	/*printf("Done with 0th \n");
	
	removeAThree(c1, c2, c3, sum);
	printf("Done with 1st\n");
	removeATwo(c1, c2, c3, sum);
	removeAOne(c1, c2, c3, sum); */
	
		if(c>0){
		
		sum+=(double) n / (double) (a+b+c);
		printf("%lld %lld %lld : %0.9f\n", a, b, c, sum);
		help(a, b+1, c-1);
	}
	
	if(b>0){
		
		sum+=(double) n / (double) (a+b+c);
		printf("%lld %lld %lld : %0.9f\n", a, b, c, sum);
		help(a+1, b-1, c);
	}
		
	if(a>0){
		
		sum+=(double) n / (double) (a+b+c);
		printf("%lld %lld %lld : %0.9f\n", a, b, c, sum);
		help(a-1, b, c);
	}
	
	
	dp[a][b][c] = (double) n / (double) (a+b+c);
