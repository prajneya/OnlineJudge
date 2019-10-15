#include<stdio.h>
#include<math.h>
#include<string.h>

char re(long long int n) { 
    if (n >= 0 && n <= 9) 
        return (char)(n + '0'); 
    else
        return (char)(n - 10 + 'A'); 
}

void reverse(char *str) { 
    long long int len = strlen(str); 
    long long int i; 
    for(i = 0; i < len/2; i++) { 
        char temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
}

int main(){
	long long int n, x, y;
	char num[1000000];
	if(scanf("%lld%lld%lld", &n, &x, &y)!=1){
		long long int c = 0;
		long long int sum = 0;
		while(n!=0){
			long long int temp = n%10;
			sum+=temp*pow(x, c);
			c++;
			n/=10;
		}
		c = 0;
		while(sum>0){
			num[c] = re(sum%y);
			c++;
			sum/=y;
		}
		num[c] = '\0';
		
		reverse(num);
		
		printf("%s\n", num);
	}
}
