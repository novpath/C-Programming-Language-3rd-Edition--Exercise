#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE *fp;
	long num;
	char stname[20];
	int i, score;
	int avg_score = 0;
	
	if((fp = fopen("./f12-1.txt", "r")) == NULL){
		printf("File open error!\n");
		exit(0);
	}
	for(i = 0; i < 5; i ++)
	{
		fscanf(fp, "%ld%s%d\n", &num, stname, &score);
		avg_score += score;
		printf("%ld%s%d\n", num, stname, score);
	}
	printf("Average score:%d\n", avg_score / 5);
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}
