#include<stdio.h>

int main(){
	long long int t;
	scanf("%lld", &t);

	while(t--){
		long long int n;
		scanf("%lld", &n);
	    
	    long long int sum = 1, adder = 1;
	    long long int count = 1, rc;
	    long long int i;
	    
	    for(i = 1; ;i++){
	    	if(sum==n){
	    		rc = count;
	    		break;
			}
			else if(sum>n){
				rc = count-1;
				break;
			}
			count++;
	    	adder+=(i*4);
	    	sum+=adder;
	    	//printf("%lld ", sum);
		}
		
		printf("%lld\n", rc);
	}
}
