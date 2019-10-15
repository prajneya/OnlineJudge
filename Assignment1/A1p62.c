#include<stdio.h>

int main(){
	int x, y, z;
	if(scanf("%d%d%d", &x, &y, &z)){
		
		int i = x;
		int j = 0;
		int count = 0;
		
		for(i = x; i <= y; i++){
			int nof = 0;
			for(j = 1; j*j<=i; j++){
				if(i%j==0){
					if(i/j!=j)
						nof+=2;
					else
						nof++;
				}
			}
			if(nof<=z){
				count++;
			}
		}
		
		printf("%d", count);
		
	}
}
