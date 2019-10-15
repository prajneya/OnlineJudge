#include<stdio.h>
#include<math.h>

int main(){
	
	int t;
	if(scanf("%d", &t)==1){
		while(t--){
			double c;
			if(scanf("%lf", &c)==1){
				double l = 0;
				double r = c; 
				
				double g = (l+r)/2;
				double ans = (g*g) + sqrt(g);
				double eps = 0.000001 ;
				int x = 0;
				while(fabs(c - ans) > eps) {
					if(ans<c){
						l = g;
					}
					else{
						r = g;
					}
					g = (l+r)/2;
					ans = (g*g) + sqrt(g);
				}
	
				printf("%0.6lf\n", g);
			}
	
			
		}
	
		return 0;
	}
	
	
	
}
