#include<stdio.h>

long long int ans[20][20][2];

long long int i, j, k;

long long int goal(long long int dig, long long int count, int flag, int num[20], long long int len){
	if(dig==len){
		if(count<=3)
			return 1;
		return 0;
	}
	
	if(ans[dig][count][flag]!=-1)
		return ans[dig][count][flag];
		
	long long int sum = 0;
	
	long long int dur = num[dig];
	if(flag==1)
		dur = 9;
		
	long long int index = 0;
	
	for(index = 0; index<=dur; index++){
		long long int temp = count;
		
		if(index!=0)
			temp++;
			
		int flagger = flag;
		
		if(index<num[dig])
			flagger = 1;
			
		sum += goal(dig+1, temp, flagger, num, len);
	}
	
	ans[dig][count][flag] = sum;
	return sum;
}

long long int help(long long int n){
	i = 0, j = 0;
	int num[20];
	while(n){
		num[i] = n%10;
		n/=10;
		i++;
	}
	long long int len = i;
	long long int temp;
	for(i = len-1; i>=len/2; i--){
		//printf("%d %lld ", num[i], i);
		temp = num[j];
		num[j] = num[i];
		num[i] = temp;
		j++;
		
	}
	
	/*for(i = 0; i<len; i++){
		printf("%d ", num[i]);
		
	}
	printf("\n");*/
	
	for(i = 0; i<20; i++){
		for(j = 0; j<20; j++){
			for(k = 0; k<2; k++){
				ans[i][j][k] = -1;
			}
		}
	}
	
	return goal(0, 0, 0, num, len);
	
}

int main(){
	long long int q;
	scanf("%lld", &q);
	while(q--){
		long long int s1, s2;
		scanf("%lld%lld", &s1, &s2);
		
		long long int x = help(s2)-help(s1-1);
		
		printf("%lld\n", x);
		
	}
}
