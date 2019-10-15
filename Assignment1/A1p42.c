#include<stdio.h>
#include<stdbool.h>

/* long long int min(long long int a, long long int b){
	if(a<=b) 
		return a;
	return b;
}

long long int max(long long int a, long long int b){
	if(a>=b) 
		return a;
	return b;
} */

/*bool check1(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3, long long int x4, long long int y4){
	
	if (x1 > x4 || x3 > x2){
		printf("check1a\n");
		return false; 
	} 
        
  

    if (y1 > y4 || y3 > y2) {
    	printf("check1b\n");
    	return false;
	}
         
	
	/*if(x1 <= x4 && x2 >= x3 && y1 <= y4 && y2 >= y3){
		return true;
	}
	
	//return false;
	return true;
} */

long long int check2(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3){
	
	if(((x2 - x1) * (y3 - y1) )==((y2 - y1) * (x3 - x1))){
		return -1;	
	}
	else if(((x2 - x1) * (y3 - y1) )>((y2 - y1) * (x3 - x1))){
		return 1;
	}
	else{
		return 0;
	}
}

bool check3(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3, long long int x4, long long int y4){
	
	if(check2(x1, y1, x2, y2, x3, y3) == -1 || check2(x1, y1, x2, y2, x4, y4) == -1 || (check2(x1, y1, x2, y2, x3, y3) ^ check2(x1, y1, x2, y2, x4, y4))){
		return true;
	}
	//printf("check3\n");
	return false;
}

bool finalcheck(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3, long long int x4, long long int y4){
	//if((check1(x1, y1, x2, y2, x3, y3, x4, y4) || check1(x1, y1, x2, y2, x4, y4, x3, y3) || check1(x2, y2, x1, y1, x3, y3, x4, y4) || check1(x2, y2, x1, y1, x4, y4, x3, y3)))
		if(check3(x1, y1, x2, y2, x3, y3, x4, y4) && check3(x3, y3, x4, y4, x1, y1, x2, y2))
			return true;
	
	//printf("finalcheck\n");
	return false;
}

int main(){
	long long int t;
	if(scanf("%lld", &t)==1){
		while(t--){
		
			long long int x1, y1, x2, y2, x3, y3, x4, y4;
			
			if(scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4)!=1){
				
				/*if(!check1(x1, y1, x2, y2, x3, y3, x4, y4)){
					printf("Waddawow\n");
				}*/
				
				if(finalcheck(x1, y1, x2, y2, x3, y3, x4, y4)){
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
		}
	}
	return 0;
}
