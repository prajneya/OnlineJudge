#include<stdio.h>

int fact[1000001] = { 0 }; 

int helper(int n) { 
    if (n == 1) 
        return 1; 
  
    int ans = 1; 
	int dup = fact[n]; 
  	int c = 1; 
  
	int j = n / fact[n]; 
  
	while (j != 1) { 
		if (fact[j] == dup) 
            c += 1; 
  

        else { 
            dup = fact[j]; 
            ans = ans * (c + 1); 
            c = 1; 
        } 
  
        j = j / fact[j]; 
    } 
  
    ans = ans * (c + 1); 
  
    return ans; 
} 

void prime(){ 
    fact[1] = 1; 
  
	int i;
    for (i = 2; i < 1000001; i++) 
        fact[i] = i; 
  
    for (i = 4; i < 1000001; i += 2) 
        fact[i] = 2; 

    for (i = 3; i * i < 1000001; i++) { 
       if (fact[i] == i) { 
       		int j = 0;
			for (j = i * i; j < 1000001; j += i){  
                if (fact[j] == j) 
                    fact[j] = i; 
            } 
        } 
    } 
} 

int main(){
	int x, y, z;
	if(scanf("%d%d%d", &x, &y, &z)){
		
		prime();
		
		int i = x;
		
		int count = 0;
		
		for(i = x; i <= y; i++){
			int nof = helper(i);
			if(nof<=z){
				count++;
			}
		}
		
		printf("%d", count);
		
	}
}
