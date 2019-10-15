#include<stdio.h>  
#include<stdbool.h>

int min(int a, int b){
	if(a<=b) 
		return a;
	return b;
}

int max(int a, int b){
	if(a>=b) 
		return a;
	return b;
}

bool isOnLine(int x1, int y1, int x2, int y2, int x3, int y3) { 
    if (x2 <= max(x1, x3) && x2 >= min(x1, x3) && 
        y2 <= max(y1, y3) && y2 >= min(y1, y3)) 
       return true; 
  
    return false; 
} 
  
int rot(int x1, int y1, int x2, int y2, int x3, int y3) { 
 
    int val = (y2 - y1) * (x3 - x2) - 
              (x2 - x1) * (y3 - y2); 
  
    if (val == 0) 
		return 0;
		  
    return (val > 0)? 1: 2; 
} 
  
bool checkAns(){ 

    int o1 = rot(x1, y1, x2, y2, x3, y3); 
    int o2 = rot(x1, y1, x2, y2, x4, y4); 
    int o3 = rot(x3, y3, x4, y4, x1, y1); 
    int o4 = rot(x3, y3, x4, y4, x2, y2); 

    if (o1 != o2 && o3 != o4) 
        return true; 
  

    if (o1 == 0 && isOnLine(x1, y1, x3, y3, x2, y2)) 
		return true; 
  

    if (o2 == 0 && isOnLine(x1, y1, x4, y4, x2, y2)) 
		return true; 

    if (o3 == 0 && isOnLine(x3, y3, x1, y1, x4, y4)) 
		return true; 

    if (o4 == 0 && isOnLine(x3, y3, x2, y2, x4, y4)) 
		return true; 
  
    return false; 
} 
  

int main(){ 

	int t;
	if(scanf("%d", &t)==1){
		while(t--){
		
			int x1, y1, x2, y2, x3, y3, x4, y4;
		
			if(scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4)!=1){
				
		
				if(checkAns(x1, y1, x2, y2, x3, y3, x4, y4)){
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
		
		}
  
    	return 0; 
	}
	
	
} 
