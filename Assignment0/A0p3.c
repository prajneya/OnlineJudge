#include<stdio.h>

void notec(int money){
	
	int notes[4] = {2000, 100, 50, 10};
	
	int noteco[4] = {0};
	
	int i = 0;
	
	for(i = 0; i<4; i++){
		if(money>=notes[i]){
			noteco[i] = money/notes[i];
			money -= (noteco[i]*notes[i]);
		}
	}
	
	for(i = 3; i>=0; i--){
		printf("%d ", noteco[i]);
	}
}

int main(){
	int m, y;
	scanf("%d%d", &m, &y);
	
	int i = (m*0.1*y);
	
	m+=i;
	
	notec(m);
}
