#include<stdio.h>
#include<stdlib.h>
typedef struct student{
	long num;
	char stname[20];
	int score;
} STUDENT;
int main(void)
{
	FILE *fp;
	STUDENT stu[5];
	int i, max, min;
	max = min = 0;
	
	if((fp = fopen("./f12-1.txt", "r")) == NULL){
		printf("File open error!\n");
		exit(0);
	}
	for(i = 0; i < 5; i ++)
		fscanf(fp, "%ld%s%d\n", &stu[i].num, stu[i].stname, &stu[i].score);
	for(i = 0; i < 5; i ++)
	{
		if(stu[i].score >= stu[max].score)
			max = i;
		if(stu[i].score <= stu[min].score)
			min = i;
	}
	printf("%ld %s %d\n", stu[max].num, stu[max].stname, stu[max].score);
	printf("%ld %s %d\n", stu[min].num, stu[min].stname, stu[min].score);
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}
