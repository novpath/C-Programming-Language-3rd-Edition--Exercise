#include<stdio.h>

int main(){
    int sum = 0;
    int i = 1;
    for(i = 1; i <= 100; i++){
    	if(i % 6 == 0)
    		sum += i;
	}
    printf("%d", sum);
    
    return 0;
}
