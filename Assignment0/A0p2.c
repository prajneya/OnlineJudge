#include<stdio.h>

int main(){
	int l1, l2, u1, u2, t;
	scanf("%d%d%d%d%d", &l1, &u1, &l2, &u2, &t);
	
	float ans = 0;
	
	ans = ( (float) (t-l1) / (float) (u1-l1) ) * (float) (u2-l2);
	ans = ans + (float) l2;
	
	printf("%0.2f", ans);
}
