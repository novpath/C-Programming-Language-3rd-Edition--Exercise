#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int x, sum;
	sum = 0;
	if((fp = fopen("Int_Data.dat", "ab+")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
	while(!feof(fp)){
		fscanf(fp,"%d", &x);
		sum += x;
	}
	fprintf(fp, " %d", sum);
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}

