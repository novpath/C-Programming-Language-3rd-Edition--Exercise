#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	double x;
	if((fp = fopen("f12-2.txt", "w+")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
	scanf("%lf", &x);
	while(x != -1){
		fprintf(fp, "%lf", x);
		fprintf(fp, "\n");
		scanf("%lf", &x);
	}
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}

