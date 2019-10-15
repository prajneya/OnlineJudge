#include<stdio.h>
#include<string.h>

int main(){
	long long int t;
	scanf("%lld", &t);
	char str[500005];
	while(t--){
		scanf("%s", str);
		
		long long int n = strlen(str);
		
		long long int tcount=0, count=0;
		
		long long int i;
		
		for(i = 0; i<n; i++){
			if(str[i]=='('){
				tcount++;
				if(tcount>count){
					count = tcount;
				}
			}
			else{
				tcount--;
			}
		}
		
		printf("%lld\n", count);
	}
}
