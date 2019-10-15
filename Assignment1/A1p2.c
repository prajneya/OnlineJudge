#include<stdio.h>
#include<math.h>

int main(){

	long int t;
	if(scanf("%ld", &t)==1){
		long int n;
		while(t--){
				if(scanf("%ld", &n)==1){
				long int count = 0; 
  				
  				count = floor(sqrt(n));
  
 		   		printf("%ld\n", count); 
			}
			return 0;
		}
		
	}
}
